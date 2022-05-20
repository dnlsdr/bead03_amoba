#include "MyApplication.hpp"


int main()
{
    MyApplication* app = new MyApplication();
    app->handle(app);

    return 0;
}
