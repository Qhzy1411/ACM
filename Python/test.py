import os
import re

def add_number_to_filenames(directory, increment=756):
    """
    将指定目录下所有纯数字文件名（不含扩展名）的数字加上指定增量
    
    :param directory: 要处理的目录路径
    :param increment: 要增加的数字，默认为756
    """
    # 编译匹配纯数字文件名的正则表达式
    pattern = re.compile(r'^(\d+)(\..*)?$')
    
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            # 提取数字部分和扩展名
            number_str = match.group(1)
            extension = match.group(2) if match.group(2) else ''
            
            try:
                original_num = int(number_str)
                new_num = original_num + increment
                new_filename = f"{new_num}{extension}"
                
                # 构建完整路径
                old_path = os.path.join(directory, filename)
                new_path = os.path.join(directory, new_filename)
                
                # 重命名文件
                os.rename(old_path, new_path)
                print(f"Renamed: {filename} -> {new_filename}")
            except ValueError:
                print(f"Skipping {filename} - not a valid number")
        else:
            print(f"Skipping {filename} - doesn't match pattern")

if __name__ == "__main__":
    # 使用示例
    target_directory = "G:\\Temp\\3224403794\\universal\\material\\ui\\driver"
    if os.path.isdir(target_directory):
        add_number_to_filenames(target_directory)
        print("处理完成!")
    else:
        print("错误: 指定的路径不是一个有效目录")