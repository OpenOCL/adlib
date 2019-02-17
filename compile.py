import subprocess
import os

# path join
def pjoin(path_list):
    return ' '.join(path_list)

src_dir = 'adlib'
test_dir = 'test'

includes = '-I ' + os.getcwd()

# compile command string
h_files = ['atomic.h','exceptions.h','typedefs.h','utils.h']
test_files = ['test_expression.cc']

h_path = [os.path.join(src_dir,f) for f in h_files];
test_path = [os.path.join(test_dir,f) for f in test_files];

compile_str = 'g++ -c ' + pjoin(test_path) + ' '  + pjoin(h_path) + ' -o adlib.o ' + includes
link_str = "g++ -o test_expression.cc adlib.o"

p = subprocess.run(compile_str, shell=True)
if p.returncode == 0:
    subprocess.run(link_str, shell=True)
