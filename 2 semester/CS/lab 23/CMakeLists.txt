
project(lab_23 C)

set(CMAKE_C_STANDARD 99)

set(SRC_FILES queue/queue.c queue/queue.h)
set(SRC_FILES ${SRC_FILES} rbtree/rbtree.c rbtree/rbtree.h)
set(SRC_FILES ${SRC_FILES} array/array.c array/array.h)
set(SRC_FILES ${SRC_FILES} stack/stack.c stack/stack.h)
set(SRC_FILES ${SRC_FILES} exception/exception.c exception/exception.h exception/exceptions_list.h)
add_executable(lab_23 main.c ${SRC_FILES})

