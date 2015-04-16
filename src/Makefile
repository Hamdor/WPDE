cc=clang++
boostpath=/usr/local/Cellar/boost/1.57.0/include
cflags=-std=c++11

all: clean boost_scoped_ptr boost_shared_ptr boost_intrusive_ptr \
	std_unique_ptr std_unique_ptr_ownership std_weak_ptr

boost_shared_ptr:
	${cc} ${cflags} boost_shared_ptr.cpp -I ${boostpath} -o boost_shared_ptr

boost_scoped_ptr:
	${cc} ${cflags} boost_scoped_ptr.cpp -I ${boostpath} -o boost_scoped_ptr

boost_intrusive_ptr:
	${cc} ${cflags} boost_intrusive_ptr.cpp -I ${boostpath} -o boost_intrusive_ptr

std_unique_ptr:
	${cc} -std=c++14 std_unique_ptr.cpp -o std_unique_ptr

std_unique_ptr_ownership:
	${cc} ${cflags} std_unique_ptr_ownership.cpp -o std_unique_ptr_ownership

std_weak_ptr:
	${cc} ${cflags} std_weak_ptr.cpp -o std_weak_ptr

clean:
	rm -f boost_shared_ptr
	rm -f boost_scoped_ptr
	rm -f boost_intrusive_ptr
	rm -f std_unique_ptr
	rm -f std_unique_ptr_ownership
	rm -f std_weak_ptr
