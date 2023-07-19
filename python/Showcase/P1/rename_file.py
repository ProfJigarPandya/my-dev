import os

def rename_file():

    #(1) get filenames from the folder
    file_list = os.listdir(r"prank")
    print(file_list)

    saved_path=os.getcwd()
    print("Current working directory is"+saved_path)
    #(2) for each file, rename filename
    os.chdir(r"prank")
    for file_name in file_list:
        print("Old Name---"+file_name)
        print("New Name---"+file_name.translate(None, "0123456789"))
    
        os.rename(file_name,file_name.translate(None, "0123456789"))
    os.chdir(saved_path)
rename_file()
