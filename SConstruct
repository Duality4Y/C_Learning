# Program('test',Glob('*.c'))
# Object('hello.c')
# Library('hi', 'hello.c')
# SharedLibrary('hi', 'hello.c')

# hello_objs = Object('hello.c')
# prog_list = Program(hello_objs)
# print(hello_objs)
# print(prog_list)

# print(GetBuildPath(hello_objs))

env = Environment(CC='gcc', CCFLAGS='-Wall')

src_path = ['src/']
src = Split('main.c stack.c stacktesting.c ops.c')
env.Repository(src_path)
env.Program('main', [src])
