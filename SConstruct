# Program('test',Glob('*.c'))
# Object('hello.c')
# Library('hi', 'hello.c')
# SharedLibrary('hi', 'hello.c')

# hello_objs = Object('hello.c')
# prog_list = Program(hello_objs)
# print(hello_objs)
# print(prog_list)

# print(GetBuildPath(hello_objs))

src_path = ['src/']
src = Split('main.c stack.c stacktesting.c')
Repository(src_path)
Program('main', [src])
