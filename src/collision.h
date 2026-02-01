#ifndef COLLISION_H
#define COLLISION_H

#include "raylib.h"
#include <vector>

void ResolvePlayerBuildingCollision(Rectangle& destrect, const std::vector<Rectangle>& buildings);
void ResolvePlayerIdleCollision(Rectangle& playerRect, const Rectangle& idleRect, Vector2& conversationPosition, bool& showConversation, int& conversationStep, bool& firstCollisionOccurred, bool &sequence5);
void ResolvePlayerKeyCollision(Rectangle& playerRect, Rectangle& keyRect, bool& keyFound);

void ResolvePlayerHospitalCollision(Rectangle& playerRect, const Rectangle& hospitalRect, bool& insideHospital, bool& playerPositionUpdated);
void ResolvePlayerCDSCollision(Rectangle& playerRect, const Rectangle& cdsRect, bool& insideCDS, bool& playerPositionUpdated);
void ResolvePlayerAudiCollision(Rectangle& playerRect, const Rectangle& audiRect, bool& insideAudi, bool& playerPositionUpdated);
void ResolvePlayerLibraryCollision(Rectangle& playerRect, const Rectangle& libraryRect, bool& insideLibrary, bool& playerPositionUpdated);
void ResolvePlayerClassroomCollision(Rectangle& playerRect, const Rectangle& libraryRect, bool& insideLibrary, bool& playerPositionUpdated);
void InsideHospital(Rectangle& playerRect, const std::vector<Rectangle>& hospitalCollisions);
// void InsideLibrary(Rectangle& playerRect, const std::vector<Rectangle>& libraryCollisions);
// void InsideHall(Rectangle& playerRect, const std::vector<Rectangle>& hallCollisions);
void InsideMaze(Rectangle& playerRect, const std::vector<Rectangle>& mazeCollisions);
//void InsideClassroom(Rectangle& playerRect, const std::vector<Rectangle>& classroomCollisions);
void InsideAudi(Rectangle& playerRect, const std::vector<Rectangle>& audiCollisions);
void ResolvePlayerBookCollision(Rectangle& playerRect, Rectangle& bookRect, bool& bookFound);
void ResolvePlayerUsbCollision(Rectangle& playerRect, Rectangle& usbRect, bool& usbFound, bool& showcipher);
void ResolvePlayerHallCollision(Rectangle& playerRect, const Rectangle& hallRect, bool& insideHall, bool& playerPositionUpdated);
void ResolvePlayerHackerCollision(Rectangle& playerRect, const Rectangle& hackerRect, bool& showHackerConvo, int& hackerConvoStep);
void ResolvePlayerGardenerCollision(Rectangle& playerRect, const Rectangle& gardenerRect, bool& showGardenerConvo, int& gardenerConvoStep);
void ResolvePlayerProCollision(Rectangle& playerRect, const Rectangle& proRect, bool& showProConvo, int& proConvoStep,bool &sequence6);
void ResolvePlayerMazeCollision(Rectangle& playerRect, const Rectangle& mazeRect, bool& mazeActive, bool& playerPositionUpdated);
void ResolvePlayerApuCollision(Rectangle& playerRect, const Rectangle& apuRect, Vector2& conversationPosition, bool& showApuConvo, int& apuConvoStep, bool& firstApuCollision);
void ResolvePlayerBhaiCollision(Rectangle& playerRect, const Rectangle& bhaiRect,Vector2& conversationPosition, bool& showBhaiConvo, int& bhaiConvoStep, bool& firstBhaiCollision);
void ResolvePlayerAnsCollision(Rectangle& playerRect, Rectangle& ansRect, bool& ans, bool& showAns);
void FinalCollision(Rectangle& playerRect, const Rectangle& finalRect, bool& insideFinal);


#endif // COLLISION_H