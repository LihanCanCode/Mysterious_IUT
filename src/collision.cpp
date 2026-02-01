#include "collision.h"
#include <iostream>
#include <cmath>

void ResolvePlayerBuildingCollision(Rectangle& destrect, const std::vector<Rectangle>& buildings) {
    for (const auto& building : buildings) {
        float overlapX = (destrect.x + destrect.width / 2) - (building.x + building.width / 2);
        float overlapY = (destrect.y + destrect.height / 2) - (building.y + building.height / 2);
        float halfWidthSum = (destrect.width + building.width) / 2;
        float halfHeightSum = (destrect.height + building.height) / 2;

        if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
            float penetrationX = halfWidthSum - fabs(overlapX);
            float penetrationY = halfHeightSum - fabs(overlapY);

            if (penetrationX < penetrationY) {
                if (overlapX > 0) {
                    destrect.x += penetrationX;
                } else {
                    destrect.x -= penetrationX;
                }
            } else {
                if (overlapY > 0) {
                    destrect.y += penetrationY;
                } else {
                    destrect.y -= penetrationY;
                }
            }
        }
    }
}

void ResolvePlayerIdleCollision(Rectangle& playerRect, const Rectangle& idleRect, Vector2& conversationPosition, bool& showConversation, int& conversationStep, bool& firstCollisionOccurred,bool &sequence5) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (idleRect.x + idleRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (idleRect.y + idleRect.height / 2);
    float halfWidthSum = (playerRect.width + idleRect.width) / 2;
    float halfHeightSum = (playerRect.height + idleRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        float penetrationX = halfWidthSum - fabs(overlapX);
        float penetrationY = halfHeightSum - fabs(overlapY);

        std::cout << "Collision with idle character detected!" << std::endl;

        if (penetrationX < penetrationY) {
            if (overlapX > 0) {
                playerRect.x += penetrationX;
            } else {
                playerRect.x -= penetrationX;
            }
        } else {
            if (overlapY > 0) {
                playerRect.y += penetrationY;
            } else {
                playerRect.y -= penetrationY;
            }
        }

        conversationPosition = {playerRect.x - 50, playerRect.y - 280};
        showConversation = true;


        if (!firstCollisionOccurred) {
            conversationStep = 0;
            firstCollisionOccurred = true;
        } else {
            conversationStep = 2;
        }
        if(sequence5){
            conversationStep=5;
        }
        
    }
}


void ResolvePlayerApuCollision(Rectangle& playerRect, const Rectangle& apuRect, Vector2& conversationPosition, bool& showConversation, int& conversationStep, bool& firstApuCollision) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (apuRect.x + apuRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (apuRect.y + apuRect.height / 2);
    float halfWidthSum = (playerRect.width + apuRect.width) / 2;
    float halfHeightSum = (playerRect.height + apuRect.height) / 2;
    

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        float penetrationX = halfWidthSum - fabs(overlapX);
        float penetrationY = halfHeightSum - fabs(overlapY);

        std::cout << "Collision with Apu detected!" << std::endl;

        if (penetrationX < penetrationY) {
            if (overlapX > 0) {
                playerRect.x += penetrationX;
            } else {
                playerRect.x -= penetrationX;
            }
        } else {
            if (overlapY > 0) {
                playerRect.y += penetrationY;
            } else {
                playerRect.y -= penetrationY;
            }
        }

        conversationPosition = {apuRect.x -660, apuRect.y-600 };
        //showConversation = true;
        if(conversationStep!=6){
            showConversation = true;
        }
        if (!firstApuCollision) {
            conversationStep = 0;
            firstApuCollision = true;
        } else {
            conversationStep = 0;
        }
    }
}


//bhai
void ResolvePlayerBhaiCollision(Rectangle& playerRect, const Rectangle& bhaiRect, Vector2& conversationPosition, bool& showConversation, int& conversationStep, bool& firstCollisionOccurred) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (bhaiRect.x + bhaiRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (bhaiRect.y + bhaiRect.height / 2);
    float halfWidthSum = (playerRect.width + bhaiRect.width) / 2;
    float halfHeightSum = (playerRect.height + bhaiRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        float penetrationX = halfWidthSum - fabs(overlapX);
        float penetrationY = halfHeightSum - fabs(overlapY);

        std::cout << "Collision with Bhai detected!" << std::endl;

        if (penetrationX < penetrationY) {
            if (overlapX > 0) {
                playerRect.x += penetrationX;
            } else {
                playerRect.x -= penetrationX;
            }
        } else {
            if (overlapY > 0) {
                playerRect.y += penetrationY;
            } else {
                playerRect.y -= penetrationY;
            }
        }


        conversationPosition = {playerRect.x - 720, playerRect.y - 560};

        
        showConversation = true;
            
        if (!firstCollisionOccurred) {
            conversationStep = 0;
            firstCollisionOccurred = true;
        } else {
            //conversationStep = 2;
            //showConversation = true;
            //conversationStep = 8;
        }
    }
}

void ResolvePlayerKeyCollision(Rectangle& playerRect, Rectangle& keyRect, bool& keyFound) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (keyRect.x + keyRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (keyRect.y + keyRect.height / 2);
    float halfWidthSum = (playerRect.width + keyRect.width) / 2;
    float halfHeightSum = (playerRect.height + keyRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with key detected!" << std::endl;
        keyFound = true;
    }
}



void ResolvePlayerBookCollision(Rectangle& playerRect, Rectangle& keyRect, bool& bookFound) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (keyRect.x + keyRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (keyRect.y + keyRect.height / 2);
    float halfWidthSum = (playerRect.width + keyRect.width) / 2;
    float halfHeightSum = (playerRect.height + keyRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with book detected!" << std::endl;
        bookFound = true;
    }
}

void ResolvePlayerUsbCollision(Rectangle& playerRect, Rectangle& usbRect, bool& usbFound, bool& showcipher) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (usbRect.x + usbRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (usbRect.y + usbRect.height / 2);
    float halfWidthSum = (playerRect.width + usbRect.width) / 2;
    float halfHeightSum = (playerRect.height + usbRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with usb detected!" << std::endl;
        usbFound = true;
        showcipher = true; // Show the cipher when the USB is found
    }
}

void ResolvePlayerHospitalCollision(Rectangle& playerRect, const Rectangle& hospitalRect, bool& insideHospital, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (hospitalRect.x + hospitalRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (hospitalRect.y + hospitalRect.height / 2);
    float halfWidthSum = (playerRect.width + hospitalRect.width) / 2;
    float halfHeightSum = (playerRect.height + hospitalRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with hospital detected!" << std::endl;
        insideHospital = true;

        if (!playerPositionUpdated) {
            playerRect.x = 1259;
            playerRect.y = 56;
            playerPositionUpdated = true;
        }
    }
}

void ResolvePlayerHallCollision(Rectangle& playerRect, const Rectangle& hallRect, bool& insideHall, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (hallRect.x + hallRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (hallRect.y + hallRect.height / 2);
    float halfWidthSum = (playerRect.width + hallRect.width) / 2;
    float halfHeightSum = (playerRect.height + hallRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with hall detected!" << std::endl;
        insideHall = true;

        if (!playerPositionUpdated) {
            playerRect.x = 1285;
            playerRect.y = 1502;
            playerPositionUpdated = true;
        }
    }
}

void ResolvePlayerAudiCollision(Rectangle& playerRect, const Rectangle& audiRect, bool& insideAudi, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (audiRect.x + audiRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (audiRect.y + audiRect.height / 2);
    float halfWidthSum = (playerRect.width + audiRect.width) / 2;
    float halfHeightSum = (playerRect.height + audiRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with audi detected!" << std::endl;
        insideAudi = true;

        if (!playerPositionUpdated) {
            playerRect.x = 100;
            playerRect.y = 104;
            playerPositionUpdated = true;
        }
    }
}

void ResolvePlayerHackerCollision(Rectangle& playerRect, const Rectangle& hackerRect, bool& showHackerConvo, int& hackerConvoStep) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (hackerRect.x + hackerRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (hackerRect.y + hackerRect.height / 2);
    float halfWidthSum = (playerRect.width + hackerRect.width) / 2;
    float halfHeightSum = (playerRect.height + hackerRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with hacker detected!" << std::endl;
        if(!showHackerConvo && hackerConvoStep!=7){
            showHackerConvo = true;
            hackerConvoStep = 0;
        }
    }
}

void ResolvePlayerProCollision(Rectangle& playerRect, const Rectangle& proRect, bool& showProConvo, int& proConvoStep,bool &sequence6) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (proRect.x + proRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (proRect.y + proRect.height / 2);
    float halfWidthSum = (playerRect.width + proRect.width) / 2;
    float halfHeightSum = (playerRect.height + proRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with pro detected!" << std::endl;
        if(!showProConvo && sequence6 && proConvoStep!=14){
            showProConvo = true;
            proConvoStep = 7;
        } 
        else if(!showProConvo && proConvoStep!=7 &&!sequence6){
            showProConvo = true;
            proConvoStep = 0;
        }
    }
}

void ResolvePlayerCDSCollision(Rectangle& playerRect, const Rectangle& cdsRect, bool& insideCDS, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (cdsRect.x + cdsRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (cdsRect.y + cdsRect.height / 2);
    float halfWidthSum = (playerRect.width + cdsRect.width) / 2;
    float halfHeightSum = (playerRect.height + cdsRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with CDS detected!" << std::endl;
        insideCDS = true;

        if (!playerPositionUpdated) {
            playerRect.x = 1335;
            playerRect.y = 713;
            playerPositionUpdated = true;
        }
    }
}

void ResolvePlayerLibraryCollision(Rectangle& playerRect, const Rectangle& libraryRect, bool& insideLibrary, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (libraryRect.x + libraryRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (libraryRect.y + libraryRect.height / 2);
    float halfWidthSum = (playerRect.width + libraryRect.width) / 2;
    float halfHeightSum = (playerRect.height + libraryRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with library detected!" << std::endl;
        insideLibrary = true;

        if (!playerPositionUpdated) {
            playerRect.x = 1940;
            playerRect.y = 934;
            playerPositionUpdated = true;
        }
    }
}


void ResolvePlayerMazeCollision(Rectangle& playerRect, const Rectangle& mazeRect, bool& mazeActive, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (mazeRect.x + mazeRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (mazeRect.y + mazeRect.height / 2);
    float halfWidthSum = (playerRect.width + mazeRect.width) / 2;
    float halfHeightSum = (playerRect.height + mazeRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with maze detected!" << std::endl;
        mazeActive = true;

        if (!playerPositionUpdated) {
            playerRect.x = 50;
            playerRect.y = 284;
            playerPositionUpdated = true;
        }
    }
}

void ResolvePlayerClassroomCollision(Rectangle& playerRect, const Rectangle& classroomRect, bool& insideClassroom, bool& playerPositionUpdated) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (classroomRect.x + classroomRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (classroomRect.y + classroomRect.height / 2);
    float halfWidthSum = (playerRect.width + classroomRect.width) / 2;
    float halfHeightSum = (playerRect.height + classroomRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with classroom detected!" << std::endl;
        insideClassroom = true;

        if (!playerPositionUpdated) {
            playerRect.x = 1940;
            playerRect.y = 1370;
            playerPositionUpdated = true;
        }
    }
}


void ResolvePlayerGardenerCollision(Rectangle& playerRect, const Rectangle& gardenerRect, bool& showGardenerConvo, int& gardenerConvoStep) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (gardenerRect.x + gardenerRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (gardenerRect.y + gardenerRect.height / 2);
    float halfWidthSum = (playerRect.width + gardenerRect.width) / 2;
    float halfHeightSum = (playerRect.height + gardenerRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with gardener detected!" << std::endl;
        if(!showGardenerConvo && gardenerConvoStep!=7){
            showGardenerConvo = true;
            gardenerConvoStep = 0;
        }
    }
}

void InsideHospital(Rectangle& playerRect, const std::vector<Rectangle>& hospitalCollisions) {
    for (const auto& rect : hospitalCollisions) {
        float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
        float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
        float halfWidthSum = (playerRect.width + rect.width) / 2;
        float halfHeightSum = (playerRect.height + rect.height) / 2;

        if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
            float penetrationX = halfWidthSum - fabs(overlapX);
            float penetrationY = halfHeightSum - fabs(overlapY);

            if (penetrationX < penetrationY) {
                if (overlapX > 0) {
                    playerRect.x += penetrationX;
                } else {
                    playerRect.x -= penetrationX;
                }
            } else {
                if (overlapY > 0) {
                    playerRect.y += penetrationY;
                } else {
                    playerRect.y -= penetrationY;
                }
            }
        }
    }
    if(playerRect.x>=1485) playerRect.x=1485;
    if(playerRect.x<=713) playerRect.x=713;
    if(playerRect.y>=990) playerRect.y=990;
}

void InsideMaze(Rectangle& playerRect, const std::vector<Rectangle>& mazeCollisions) {
    for (const auto& rect : mazeCollisions) {
        float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
        float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
        float halfWidthSum = (playerRect.width + rect.width) / 2;
        float halfHeightSum = (playerRect.height + rect.height) / 2;

        if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
            float penetrationX = halfWidthSum - fabs(overlapX);
            float penetrationY = halfHeightSum - fabs(overlapY);

            if (penetrationX < penetrationY) {
                if (overlapX > 0) {
                    playerRect.x += penetrationX;
                } else {
                    playerRect.x -= penetrationX;
                }
            } else {
                if (overlapY > 0) {
                    playerRect.y += penetrationY;
                } else {
                    playerRect.y -= penetrationY;
                }
            }
        }
    }
}



// void InsideLibrary(Rectangle& playerRect, const std::vector<Rectangle>& libraryCollisions) {
//     for (const auto& rect : libraryCollisions) {
//         float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
//         float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
//         float halfWidthSum = (playerRect.width + rect.width) / 2;
//         float halfHeightSum = (playerRect.height + rect.height) / 2;

//         if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
//             float penetrationX = halfWidthSum - fabs(overlapX);
//             float penetrationY = halfHeightSum - fabs(overlapY);

//             if (penetrationX < penetrationY) {
//                 if (overlapX > 0) {
//                     playerRect.x += penetrationX;
//                 } else {
//                     playerRect.x -= penetrationX;
//                 }
//             } else {
//                 if (overlapY > 0) {
//                     playerRect.y += penetrationY;
//                 } else {
//                     playerRect.y -= penetrationY;
//                 }
//             }
//         }
//     }
// }

void InsideClassroom(Rectangle& playerRect, const std::vector<Rectangle>& classroomCollisions) {
    for (const auto& rect : classroomCollisions) {
        float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
        float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
        float halfWidthSum = (playerRect.width + rect.width) / 2;
        float halfHeightSum = (playerRect.height + rect.height) / 2;

        if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
            float penetrationX = halfWidthSum - fabs(overlapX);
            float penetrationY = halfHeightSum - fabs(overlapY);

            if (penetrationX < penetrationY) {
                if (overlapX > 0) {
                    playerRect.x += penetrationX;
                } else {
                    playerRect.x -= penetrationX;
                }
            } else {
                if (overlapY > 0) {
                    playerRect.y += penetrationY;
                } else {
                    playerRect.y -= penetrationY;
                }
            }
        }
    }
}

// void InsideHall(Rectangle& playerRect,const std::vector<Rectangle>& hallCollisions) {
//     for (const auto& rect : hallCollisions) {
//         float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
//         float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
//         float halfWidthSum = (playerRect.width + rect.width) / 2;
//         float halfHeightSum = (playerRect.height + rect.height) / 2;

//         if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
//             float penetrationX = halfWidthSum - fabs(overlapX);
//             float penetrationY = halfHeightSum - fabs(overlapY);

//             if (penetrationX < penetrationY) {
//                 if (overlapX > 0) {
//                     playerRect.x += penetrationX;
//                 } else {
//                     playerRect.x -= penetrationX;
//                 }
//             } else {
//                 if (overlapY > 0) {
//                     playerRect.y += penetrationY;
//                 } else {
//                     playerRect.y -= penetrationY;
//                 }
//             }
//         }
//     }
// }

void InsideAudi(Rectangle& playerRect,const std::vector<Rectangle>& audiCollisions) {
    for (const auto& rect : audiCollisions) {
        float overlapX = (playerRect.x + playerRect.width / 2) - (rect.x + rect.width / 2);
        float overlapY = (playerRect.y + playerRect.height / 2) - (rect.y + rect.height / 2);
        float halfWidthSum = (playerRect.width + rect.width) / 2;
        float halfHeightSum = (playerRect.height + rect.height) / 2;

        if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
            float penetrationX = halfWidthSum - fabs(overlapX);
            float penetrationY = halfHeightSum - fabs(overlapY);

            if (penetrationX < penetrationY) {
                if (overlapX > 0) {
                    playerRect.x += penetrationX;
                } else {
                    playerRect.x -= penetrationX;
                }
            } else {
                if (overlapY > 0) {
                    playerRect.y += penetrationY;
                } else {
                    playerRect.y -= penetrationY;
                }
            }
        }
    }
}

void ResolvePlayerAnsCollision(Rectangle& playerRect, Rectangle& ansRect, bool& ans, bool& showAns) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (ansRect.x + ansRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (ansRect.y + ansRect.height / 2);
    float halfWidthSum = (playerRect.width + ansRect.width) / 2;
    float halfHeightSum = (playerRect.height + ansRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        std::cout << "Collision with ans detected!" << std::endl;
        ans = true;
        showAns = true;
    }
}

void FinalCollision(Rectangle& playerRect, const Rectangle& finalRect, bool& insideFinal) {
    float overlapX = (playerRect.x + playerRect.width / 2) - (finalRect.x + finalRect.width / 2);
    float overlapY = (playerRect.y + playerRect.height / 2) - (finalRect.y + finalRect.height / 2);
    float halfWidthSum = (playerRect.width + finalRect.width) / 2;
    float halfHeightSum = (playerRect.height + finalRect.height) / 2;

    if (fabs(overlapX) < halfWidthSum && fabs(overlapY) < halfHeightSum) {
        insideFinal = true;
        //showFinal = true;
    }
}