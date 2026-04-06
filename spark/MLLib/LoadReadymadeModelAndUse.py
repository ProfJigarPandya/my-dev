from pyspark.ml import PipelineModel
from pyspark.sql import SparkSession

# Initialize Spark Session
spark = SparkSession.builder.appName("DecisionTreeInduction").getOrCreate()

# Specify the path where you want to save the model
model_path = "file:////my-dev/spark/MLLib/decision_tree_buys_computer_model"

# Load the saved model
loaded_model = PipelineModel.load(model_path)

# Use it to make predictions on new data
# predictions = loaded_model.transform(new_df)
print("Model loaded and ready for use.")

# 1. Create a single sample record
# Let's test: Age="<=30", Income="Medium", Student="Yes", Credit_Rating="Fair"
sample_data = [(99, "<=30", "Medium", "Yes", "Fair")]
sample_columns = ["Record", "Age", "Income", "Student", "Credit_Rating"]

# 2. Convert to Spark DataFrame
sample_df = spark.createDataFrame(sample_data, sample_columns)

# 3. Use the loaded model to transform the data
# The loaded_model contains all necessary StringIndexers and VectorAssembler
result = loaded_model.transform(sample_df)

# 4. Display the prediction
# 0.0 usually maps to 'Yes' and 1.0 to 'No' based on frequency
result.select("Age", "Student", "Credit_Rating", "prediction").show()

