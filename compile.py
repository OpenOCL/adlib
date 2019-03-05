import subprocess
import os

# path join
def pjoin(path_list):
    return ' '.join(path_list)

def mkdir_try(path):
    try:
        os.mkdir(path)
    except:
        pass

src_dir = 'adlib'
test_dir = 'test'
include_dir = 'include'
build_dir = 'build'
obj_dir = os.path.join(build_dir, 'obj')
bin_dir = 'bin'

cflags = '-g -Wall -Wextra -std=c++14 -Wfatal-errors -Wno-unused-parameter'

mkdir_try(build_dir)
mkdir_try(obj_dir)
mkdir_try(bin_dir)

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
test_bin_paths = [os.path.join(bin_dir, f) for f in test_files];

# compile command string
hasError = False
for s,o in zip(src_paths,obj_paths):
    if hasError:
        break
    print("Compiling source "+s+"....")
    compile_str = 'g++ -c ' + cflags + ' '  + s +  ' ' + includes + ' -o ' + o
    p = subprocess.run(compile_str, shell=True)
    hasError = p.returncode


for s,o in zip(test_paths,test_obj_paths):
    if hasError:
        break
    print("Compiling test "+s+"....")
    compile_str = 'g++ -c ' + cflags + ' '  + s +  ' ' + includes + ' -o ' + o
    p = subprocess.run(compile_str, shell=True)
    hasError = p.returncode


for o,b in zip(test_obj_paths,test_bin_paths):
    if hasError:
        break
    link_str = "g++ " + o + ' ' + pjoin(obj_paths) + ' -o ' + b
    print("Linking test " + b  + " ....")
    subprocess.run(link_str, shell=True)
