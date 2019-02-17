import subprocess
import os

# path join
def pjoin(path_list):
    return ' '.join(path_list)

src_dir = 'adlib'
test_dir = 'test'
include_dir = 'include'

includes = '-I ' + os.getcwd() + ' -I ' + include_dir + ' -I ' + src_dir

src_files = ['assignment.cc','sym_primitive.cc','atomic.cc']
h_files = ['atomic.h','exceptions.h','typedefs.h','utils.h','assignment.h']
public_files = []
test_files = ['test_expression.cc']

src_files = [os.path.join(src_dir,f) for f in src_files];
h_files = [os.path.join(src_dir,f) for f in h_files];
public_files = [os.path.join(include_dir,f) for f in public_files];
test_files = [os.path.join(test_dir,f) for f in test_files];

# compile command string
hasError = False
for s in src_files:
    print("Compiling "+s+"....")
    if hasError:
        break
    compile_str = 'g++ -c '  + s + ' '  + pjoin(h_files) + ' ' + pjoin(public_files) + ' ' + includes
    p = subprocess.run(compile_str, shell=True)
    hasError = p.returncode

link_str = "g++ -o test_expression test_expression.o"

p = subprocess.run(compile_str, shell=True)
if p.returncode == 0:
    print("Linking....")
    subprocess.run(link_str, shell=True)
