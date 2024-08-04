#include "headers.h"

<<<<<<< HEAD
using namespace std;

int main() {
    cout << "Hi, Hello, ¾È³ç\n";

    // TODO

    return 0;
=======
int main(void) {
    system("chcp 65001");
    Community* community = new Community();
    Controller controller(community);
    controller.run();
>>>>>>> 369c9c12ddd0036be44104d118d969b06cc4fc1c
}