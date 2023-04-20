#include <windows.h>
#include <GLFW/glfw3.h>

// change this to int main() to allow the console
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char *, int nShowCmd)
{
    GLFWwindow *window;
    int windowSizeW = 640, windowSizeH = 480;

    // initialize the library
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    int count, windowWidth, windowHeight, monitorX, monitorY;

    // I am assuming that main monitor is in the 0 position
    GLFWmonitor **monitors = glfwGetMonitors(&count);
    const GLFWvidmode *videoMode = glfwGetVideoMode(monitors[0]);
    // width: 75% of the screen
    windowWidth = static_cast<int>(videoMode->width / 1.5);
    // aspect ratio 16 to 9
    windowHeight = static_cast<int>(videoMode->height / 16 * 9);

    glfwGetMonitorPos(monitors[0], &monitorX, &monitorY);

    // set the visibility window hint to false for subsequent window creation
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    // create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(windowSizeW, windowSizeH, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // make the window's context current
    glfwMakeContextCurrent(window);

    // reset the window hints to default
    glfwDefaultWindowHints();

    glfwSetWindowPos(window,
                     monitorX + (videoMode->width - windowWidth) / 2,
                     monitorY + (videoMode->height - windowHeight) / 2);

    // show the window
    glfwShowWindow(window);

    // uncomment following line to see the border of window
    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_TRUE);

    float fAngle = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.0f, 0.0f, 0.2f);
        glClearColor(0.0f, 0.0f, 0.0f, 0.2f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
