from pyspark.sql import SparkSession
from pyspark.ml import Pipeline
from pyspark.ml.feature import StringIndexer, VectorAssembler
from pyspark.ml.classification import DecisionTreeClassifier
from pyspark.ml.evaluation import MulticlassClassificationEvaluator

# 1. Initialize Spark Session
spark = SparkSession.builder.appName("DecisionTreeInduction").getOrCreate()

# 2. Create the dataset
data = [
    (1, "<=30", "High", "No", "Fair", "No"),
    (2, "<=30", "High", "No", "Excellent", "No"),
    (3, "31...40", "High", "No", "Fair", "Yes"),
    (4, ">40", "Medium", "No", "Fair", "Yes"),
    (5, ">40", "Low", "Yes", "Fair", "Yes"),
    (6, ">40", "Low", "Yes", "Excellent", "No"),
    (7, "31...40", "Low", "Yes", "Excellent", "Yes"),
    (8, "<=30", "Medium", "No", "Fair", "No"),
    (9, "<=30", "Low", "Yes", "Fair", "Yes"),
    (10, ">40", "Medium", "Yes", "Fair", "Yes"),
    (11, "<=30", "Medium", "Yes", "Excellent", "Yes"),
    (12, "31...40", "Medium", "No", "Excellent", "Yes"),
    (13, "31...40", "High", "Yes", "Fair", "Yes"),
    (14, ">40", "Medium", "No", "Excellent", "No")
]

columns = ["Record", "Age", "Income", "Student", "Credit_Rating", "Buys_Computer"]
df = spark.createDataFrame(data, columns)

# 3. Preprocessing: Convert Strings to Numeric Indices
categorical_cols = ["Age", "Income", "Student", "Credit_Rating"]
indexers = [StringIndexer(inputCol=col, outputCol=col+"_idx") for col in categorical_cols]

# Index the target label "Buys_Computer"
label_indexer = StringIndexer(inputCol="Buys_Computer", outputCol="label")

# 4. Feature Engineering: Combine features into a single vector
assembler = VectorAssembler(
    inputCols=[col+"_idx" for col in categorical_cols], 
    outputCol="features"
)

# 5. Define Model
dt = DecisionTreeClassifier(labelCol="label", featuresCol="features")

# 6. Build and Train Pipeline
pipeline = Pipeline(stages=indexers + [label_indexer, assembler, dt])
model = pipeline.fit(df)

# 7. Make Predictions
predictions = model.transform(df)
predictions.select("Age", "Income", "Student", "Credit_Rating", "Buys_Computer", "prediction").show()

# Optional: View tree logic
print(model.stages[-1].toDebugString)


# 1. Initialize the evaluator
# We specify 'accuracy' as the metric. 
# 'label' and 'prediction' are the column names in your predictions DataFrame.
evaluator = MulticlassClassificationEvaluator(
    labelCol="label", 
    predictionCol="prediction", 
    metricName="accuracy"
)

# 2. Calculate accuracy
accuracy = evaluator.evaluate(predictions)
print(f"Model Accuracy: {accuracy * 100:.2f}%")

# 3. Calculate Test Error (1 - Accuracy)
print(f"Test Error: {(1.0 - accuracy) * 100:.2f}%")


predictions.groupBy("Buys_Computer", "prediction").count().show()

'''
Label Mapping (By Frequency)

    Feature 0 (Age): 0: <=30, 1: >40, 2: 31...40
    Feature 2 (Student): 0: No, 1: Yes
    Feature 3 (Credit_Rating): 0: Fair, 1: Excellent
    Target (Buys_Computer): 0: Yes, 1: No
'''
# Specify the path where you want to save the model
model_path = "file:////my-dev/spark/MLLib/decision_tree_buys_computer_model"

# Save the entire pipeline model
model.write().overwrite().save(model_path)

print(f"Model saved successfully to: {model_path}")

