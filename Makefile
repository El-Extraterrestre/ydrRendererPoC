INCLUDES = -I./util/external/glm -I./util/gli -I/usr/include -I/usr/local/include 
LIBS = -lSDL3 -lGL -lGLEW
CXX = g++

SRC = app.cpp geometry/drawable.cpp geometry/model.cpp geometry/World.cpp graphics/Shader.cpp graphics/Camera.cpp graphics/GUI.cpp graphics/GraphicsManager.cpp graphics/ImGUI/imgui.cpp graphics/ImGUI/imgui_draw.cpp graphics/ImGUI/imgui_tables.cpp graphics/ImGUI/imgui_widgets.cpp graphics/ImGUI/imgui_impl_opengl3.cpp graphics/ImGUI/imgui_impl_sdl3.cpp util/utility.cpp util/kaitai/kaitaistream.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIBS)

$(OBJ): %.o: %.cpp
	$(CXX) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)