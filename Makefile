CFLAGS = -std=c++17 -O2 -g
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr -lXi #-lXxf86vm

VulkanTest: src/*.cpp libs/*.hpp
	g++ $(CFLAGS) -o VulkanTest *.cpp $(LDFLAGS) && ./compile.sh

.PHONY: test clean

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest