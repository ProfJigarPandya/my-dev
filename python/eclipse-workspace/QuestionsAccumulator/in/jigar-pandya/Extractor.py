'''
Created on 17-Nov-2022

@author: jigarpandya

Source reference courtesy https://github.com/nmolivo/tesu_scraper/blob/master/Python_Blogs/01_extract_from_MSWord.ipynb
'''
import os
import zipfile
import re
import xml.dom.minidom


datapath='../../data'
names=os.listdir(datapath)
for name in names:
    filename = os.path.join(datapath, name)
    if(not filename.endswith(".docx")):
        continue
    document = zipfile.ZipFile(filename)

    xml_content = document.read('word/document.xml')
    xml_str = str(xml_content)
    
    whqlink_list = re.findall("((?:What|Where|Why|Who|Whose|Whom|When|How|Which) [^?]*.?)",xml_str)
    for question in whqlink_list:   
        print(question)
    
    descqlink_list=re.findall("((?:List|Define|Tell|Describe|Recite|Recall|Identify|Show|Label|Tabulate|Quote|Name|Describe|Explain|Paraphrase|Restate|Associate|Contrast|Summarize|Differentiate|Interpret|Discuss|Calculate|Predict|Apply|Solve|Illustrate|Use|Demonstrate|Determine|Model|Experiment|Show|Examine|Modify|Classify|Outline|Break down|Categorize|Analyze|Diagram|Illustrate|Infer|Select|Assess|Decide|Choose|Rank|Grade|Test|Measure|Defend|Recommend|Convince|Select|Judge|Support|Conclude|Argue|Justify|Compare|Summarize|Evaluate|Design|Formulate|Build|Invent|Create|Compose|Generate|Derive|Modify|Develop|Integrate) [^.]*.)",xml_str)
    for question in descqlink_list:
        print(question) 