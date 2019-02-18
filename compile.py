import subprocess
import os

# path join
def pjoin(path_list):
    return ' '.join(path_list)

src_dir = 'adlib'
test_dir = 'test'
include_dir = 'include'
build_dir = 'build'
obj_dir = os.path.join(build_dir, 'obj')

try:
    os.mkdir(build_dir)
    os.mkdir(obj_dir)
except:
    pass

includes = '-I ' + os.getcwd() + ' -I ' + include_dir + ' -I ' + src_dir

src_files = ['assignment','sym_primitive','atomic']
h_files = ['atomic','exceptions','typedefs','utils','assignment']
public_files = []
test_files = ['test_expression']

src_paths = [os.path.join(src_dir, f) + '.cc' for f in src_files];
h_paths = [os.path.join(src_dir, f) + '.h' for f in h_files];
public_paths = [os.path.join(include_dir, f) + '.h' for f in public_files];
test_paths = [os.path.join(test_dir, f) + '.cc' for f in test_files];

obj_paths = [os.path.join(obj_dir, f) + '.o' for f in src_files];
test_obj_paths = [os.path.join(obj_dir, f) + '.o' for f in test_files];

# compile command string
hasError = False
for s,o in zip(src_paths,obj_paths):
    print("Compiling source "+s+"....")
    if hasError:
        break
    compile_str = 'g++ -c '  + s +  ' ' + includes + ' -o ' + o
    p = subprocess.run(compile_str, shell=True)
    hasError = p.returncode

for s,o in zip(test_paths,test_obj_paths):
    print("Compiling test "+s+"....")
    if hasError:
        break
    compile_str = 'g++ -c '  + s +  ' ' + includes + ' -o ' + o
    p = subprocess.run(compile_str, shell=True)
    hasError = p.returncode

link_str = "g++ -o test_expression " + " ".join(obj_paths) + ' ' + " ".join(test_obj_paths)

p = subprocess.run(compile_str, shell=True)
if p.returncode == 0:
    print("Linking....")
    subprocess.run(link_str, shell=True)
