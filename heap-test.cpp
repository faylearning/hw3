#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "heap.h"

int main(){
    Heap<int, std::less<int>> testH(4, std::less<int>());

    testH.push(55);
    testH.push(153);
    testH.push(347);
    testH.push(467);
    testH.push(438);
    testH.push(28);
    testH.push(205);
    testH.push(189);
    testH.push(208);
    testH.push(33);
    testH.push(297);
    testH.push(411);
    testH.push(205);
    testH.push(20);
    testH.push(253);
    testH.push(15);
    testH.push(369);
    testH.push(183);
    testH.push(133);
    testH.push(155);
    testH.push(428);
    testH.push(405);
    testH.push(302);
    testH.push(235);
    testH.push(500);
    testH.push(234);
    testH.push(69);
    testH.push(333);
    testH.push(119);
    testH.push(430);
    testH.push(487);




    // 55 153 347 467 438 28 205 189 308 33 297 411 205 20 253 15 369 183 133 155 428 405 302 235 500 234 69 333 119 430 487 57 466 166 288 275 179 106 117 466 466 231 336 473 211 448 330 295 392 445

    int s = testH.size();
    for (int i = 0; i < s; i++){ 
        std::cout << "top element: " << testH.top() << std::endl;;
        testH.pop();
    }
    
    





}

