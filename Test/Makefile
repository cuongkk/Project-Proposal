# Makefile

# Tên file đầu ra
TARGET = Main

# File nguồn
SRC = Test/Test.cpp

# Biến biên dịch
CXX = g++
CXXFLAGS = -g -I/usr/include/mysql
LDFLAGS = -lmysqlclient -L/usr/lib/x86_64-linux-gnu

# Luật build
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Luật clean
clean:
	rm -f $(TARGET)
