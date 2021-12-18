#include <cstdio>

//#include <GLES3/gl3.h>
//#define GLFW_INCLUDE_NONE

#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>

int main(void)
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    int major = 0, minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    //printf("%d.%d\n", major, minor);
    printf("%s\n", glGetString(GL_VERSION));
    //printf("%s\n", glGetString(GL_VENDOR));
    printf("%s\n", glGetString(GL_RENDERER));
    //printf("%s\n", glGetString(GL_EXTENSIONS));

    const char *source[] = {
      "#version 300 es\n",
      "in vec4 position;",
      "void main(void) {",
      "  gl_Position = position;",
      "}",
    };

    GLuint shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, sizeof source / sizeof source[0], source, 0);
    glCompileShader(shader);

    GLint result = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
      GLint len = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
      GLchar log[len];
      glGetShaderInfoLog(shader, len, &len, log);
      printf("%s\n", log);
    }

    glClearColor(0.1, 0.1, 0.1, 1);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

