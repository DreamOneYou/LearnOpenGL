#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit(); // 用于初始化GLFW库
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 这行代码用于设置OpenGL上下文的版本号，当前主版本号为3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 这行代码用于设置OpenGL上下文的次版本号。当前次版本号为3；
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 这行代码用于设置OpenGL版本的属性，有两种属性，
    // 分别为：兼容性和核心。兼容性包含了所有已经弃用的特性，而核心仅包含现代功能。这行代码将profile设置为核心profile，以便只使用现代OpenGL属性。

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    /*
        创建一个opengl渲染窗口；
        第一个null，是打开方式设置，如果使用null，则在窗口模式下打开。如果需要在全屏模式下打开，可以传递一个GLFWmonitor* 类型的变量。
    */
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate(); // 用于释放GLFW库使用的所有资源并清理内部分配的数据。
        return -1;
    }
    // 将GLFW窗口的openGL上下文设置为当前线程的上下文。这就意味着我们可以在这个窗口中使用OpenGL函数。通常GLFW窗口创建后立即调用这个函数
    glfwMakeContextCurrent(window); 
    // 设置一个回调函数，用于在窗口的帧缓冲大小发生变化时执行一些操作。当窗口大小改变时，帧缓冲区的大小也会随之发生变化。这时，就需要更新opengl窗口的尺寸以匹配新的帧缓冲区的尺寸。
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    // 用于GLAD加载OpenGL函数指针的代码。GLAD是一个用于管理和加载OpenGL函数指针的库。
    // 这行代码告诉GLAD使用GLFW的 glfwGetProcAddress函数作为加载器来加载正确的OpenGL函数指针。
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        /* 这行代码在双缓冲机制中交换颜色缓冲区。当我们使用OpenGL进行渲染时，渲染过程不是直接绘制到屏幕，而是先绘制到一个缓冲区。
            双缓冲机制意味着我们有两个缓冲区：一个用于显示，而一个用于渲染。当我们完成渲染操作时，会将显示缓冲与渲染缓冲进行交换，
            从而展示渲染结果。这有助于防止屏幕闪烁（flickering）现象
        */
        glfwSwapBuffers(window);
        /*
            这行代码负责处理窗口系统事件，如按键，窗口关闭等。调用这个函数将处理所有排队事件
            它将获取并处理在主循环中发生的所有事件。确保在主循环中频繁调用glfwPollEvents,以保持程序对事件的响应。比如你在processIput按下的ESC按键。
            
        */
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    // 其中第一个0表示视口左下角的x坐标；第二个0表示视口的左下角y坐标。
    glViewport(0, 0, width, height);
}
