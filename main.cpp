#include "headers.h"

int main(void) {
    system("chcp 65001");
    Community* community = new Community();
    Controller controller(community);
    controller.run();

    return 0;
}