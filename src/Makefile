cc=clang++
boostpath=/usr/local/Cellar/boost/1.58.0/include
cflags=-std=c++11

all: clean boost_scoped_ptr shared_ptr boost_intrusive_ptr \
	std_unique_ptr std_unique_ptr_ownership std_weak_ptr own_shared_ptr

shared_ptr:
	${cc} ${cflags} shared_ptr.cpp -o shared_ptr

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

own_shared_ptr:
	${cc} ${cflags} own_shared_ptr.cpp -o own_shared_ptr

clean:
	rm -f shared_ptr
	rm -f boost_scoped_ptr
	rm -f boost_intrusive_ptr
	rm -f std_unique_ptr
	rm -f std_unique_ptr_ownership
	rm -f std_weak_ptr
	rm -f own_shared_ptr
