TARGET = camerus
INCLUDE_DIRS = -I/usr/include -I/usr/include/opencv4

CXX = g++-10
CXXFLAGS = -O2 -Wall $(INCLUDE_DIRS) `pkg-config --cflags opencv4`
LFLAGS += -lpthread -ljpeg -lrt
LDFLAGS = `pkg-config --libs opencv4`

INPUT = main.cpp

output: main.cpp
	$(CXX) $(CXXFLAGS) $(INPUT) -o $(TARGET) $(LFLAGS) $(LDFLAGS)
	chmod 755 $(TARGET)

clean:
	rm $(TARGETS)
