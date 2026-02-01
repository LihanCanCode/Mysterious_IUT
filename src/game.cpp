#include "game.h"
#include "collision.h"
#include "idle.h"
#include "Professor.h"

#include <iostream>
#include <vector>
using namespace std;
enum GameState {
    MAP,
    HOSPITAL
};

vector<Rectangle> buildings = { Rectangle{422,640,250,550}, //
                                Rectangle{240,2075,1330,200},   //lake er bam
                                Rectangle{1185,855,235,250},     //mosque
                                Rectangle{660,640,515,100},//lake er upor
                                Rectangle{1274,640,370,100},//lake er dan
                                Rectangle{1464,735,180,400},//lake er dan niche
                                Rectangle{760, 1190,570,225},
                                Rectangle{1473,1190,180,225},
                                Rectangle{1695, 1530, 520, 460},//right e hall
                                Rectangle{1260, 1496, 340, 190},//cds
                                Rectangle{1733, 1115, 530, 240},//right mid hall
                                Rectangle{1918, 1080, 280, 40},//right mid hall upor
                                Rectangle{1722, 634, 500, 300},//right mid hall dan
                                Rectangle{1399, 56, 270, 270}, //medical
                                Rectangle{100, 70, 550, 280}, //female
                                Rectangle{420,1190, 250, 215},
                                Rectangle{672, 830, 360, 210},//auditorium
                                Rectangle{1338, 1825, 200, 170},//right mid hall
                                Rectangle{1065,1810,120,120},
                                Rectangle{310,493,140,50}
                                };
Rectangle idleRect = {1142, 1045, 70, 95}; // Define the idle character's collision rectangle
Rectangle keyRect = {1300, 80, 32, 32}; // Define the key's collision rectangle
Rectangle mazeRect={1335, 1820, 210, 180};
Rectangle hospitalRect = {1395, 50, 280, 280}; // Define the hospital's collision rectangle
Rectangle cdsRect ={1390,1670,80,30};
Rectangle libraryRect={1940,914,150,30};
Rectangle bookRect = {1585,364,32,32}; // Define the book's collision rectangle
Rectangle classroomRect ={1965,1355,100,40};
Rectangle usbRect = {1728, 1395, 32, 32}; // Define the USB's collision rectangle
Rectangle hallRect={1840,1990,100,20};
Rectangle hackerRect= {880,975,130,120};
Rectangle gardenerRect ={1060,1800,120,120};
Rectangle audiRect={805,1040,100,15};
Rectangle proRect={1100,870,60,120};
Rectangle apuRect={300,493,170,70};
Rectangle bhaiRect={1650, 260, 200, 100};
Rectangle lastRect = {2260,330,240,170};
//drawRectangle{1750,500,,500,500}

//Inside Hospital Rectangles
vector<Rectangle> hospitalCollisions = {
    {711, 585, 260, 280},
    {1272, 227, 240, 60},
    {1042, 231, 232, 60},
    {752, 229, 208, 60},
    {939, 364, 25, 110},
    {1050, 425, 450, 25},
    {1060, 450, 245, 405},
    {690,423,225,50},
    {713,865,230,70},
    {1295,855,20,140},
    {725,56,480,65},
    {1323,56,100,40},
    {1392,98,30,100} ,
    {1274,287,210,70}
};


vector<Rectangle> libraryCOllisions ={
    {141,90,510,75},
    {757,90,750,75},
    {105,140,55,505},
    {1250,137,260,505},
    {102,717,55,315},
    {102,1105,55,562},
    {102,1742,55,150},
    {134,1900,750,150},
    {1250,893,250,595},
    {1850,76,115,580},
    {1850,890,115,595},
    {1995,115,135,335},
    {2120,115,206,125},
    {2420,115,340,125},
    {2635,240,135,206},
    {2000,540,130,448},
    {2130,750,200,235},
    {2430,750,200,235},
    {2620,547,140,448},
    {1995,1110,97,285},
    {2205,1110,97,295},
    {2445,1110,97,300},
    {2690,1110,97,300}
};



vector<Rectangle> classroomCollisions ={
    {50,838,1460,225}, // upper wall
    {1170,1063,340,155},// upper wall triangle
    {514,1038,25,410},// middle wall
    {1462,1230,40,225},//middle wall
    {50,1454,90,134},
    {206,1454,660,134},
    {940,1454,1034,134},
    {2035,1454,125,134},
    {1510,837,642,60},
    {2143,894,10,545}

};

vector<Rectangle> hallCollisions ={
   {709,626,1800,300},
   {1183,1118,823,340},
   {688,1528,330,270},
   {1018,1638,1480,210},
   {983,936,40,90},
   {983,1136,40,215},
   {983,1446,40,100},
   {693,926,40,600},
   {712,1217,260,40},
   {2467,930,40,700},
   {2172,926,40,215},
   {2172,1231,40,225},
   {2171,1556,40,100},
   {2287,1012,200,40},
   {2212,1322,250,40}
};

vector<Rectangle> audiCollisions = {
    {496,222,1100,535},
    {496,1040,1100,535},
    {50,220,300,1365}
};



vector<Rectangle> mazeCollisions ={
    {50,56,1850,115},
    {50,930,1850,100},
    {75,140,105,110},
    {75,336,105,650},
    {440,165,100,155},
    {255,225,105,215},
    {355,375,235,70},
    {592,220,100,515},
    {180,515,350,70},
    {430,585,100,160},
    {235,645,100,220},
    {335,810,240,70},
    {600,805,90,120},
    {690,680,190,70},
    {777,744,100,125},
    {865,800,530,70},
    {1502,670,110,300},
    {777,224,100,385},
    {867,545,85,70},
    {955,165,100,560},
    {1045,656,185,70},
    {1315,595,100,200},
    {1125,240,100,345},
    {1212,525,500,80},
    {1212,240,400,70},
    {1520,295,110,150},
    {1292,356,85,105},
    {1377,407,150,70},
    {1710,165,110,670}

};


Rectangle startRect = {108,137,376,150};

Rectangle exitRect = {110,320,376,150};



Game::Game(){



    GameRunning = true;
    gameStart = true;
    gameExit = false;
    playerDraw = false;

    initialized = false;
    showDebugInfo = true;
    insideHospital = false;
    insideCDS = false; 
    insideLibrary = false;
    cameraPosition = {0, 0};
    camera = {0};
    showConversation = false;  // Initialize the conversation flag
    conversationPosition = {0, 0};  // Initialize the conversation position
    conversationStep = 0;  // Initialize the conversation step
    firstCollisionOccurred = false;  // Initialize the first collision flag
    keyFound = false;  // Initialize the key found flag
    keyVisible = false; // Initialize the key visibility flag
    bookFound = false; // Initialize the book found flag
    showMystery= false;
    showMystery2= false;
    showMystery3= false;
    insideClassroom=false;
    usbFound=false;
    showcipher=false;
    showcipher2=false;
    insideHall=false;
    insideAudi=false;
    showHackerConvo=false;
    showProConvo=false;
    proConvoStep=0;
    hackerConvoStep=0;
    showGardenerConvo=false;
    gardenerConvoStep=0;
    sequence1=false;
    sequence2=false;
    sequence3=false;
    sequence4=false;
    sequence5=false;
    sequence6=false;
    sequence7=false;
    mazeActive=false;
    ans=false;
    mad=false;
    apuConvoStep=0;
    showApuConvo=false;
    firstApuCollision=false;
    apuConversationPosition={0,0};
    showBhaiConvo=false;
    bhaiConvoStep=0;
    firstBhaiCollision=false;
    bhaiConversationPosition={0,0};
    Final=false;
    finalStep=0;
    showAns=false;
    showmap=false;
    show=false;

    //healthSystem = HealthSystem();



}

void Game::Initialize() {
    SetTraceLogLevel(LOG_DEBUG);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "IUT Chronicles");

    if (!IsWindowReady()) {
        std::cout << "Failed to initialize window!" << std::endl;
        return;
    }

    player.position = {135, 2200};

    player.LoadTextures();
    idle.LoadTextures();
    map.Load("map2.png");

    camera.target = player.position;
    camera.offset = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    //collision rect for player 
    SetTargetFPS(60);
    initialized = true;

    const char* menuFiles[3] = {"menu1.png", "menu2.png", "menu3.png"};
    for (int i = 0; i < 3; i++) {
        menu[i] = LoadTexture(menuFiles[i]);
    }

    const char* conversationFiles[8] = {
        "conversation1.png", "conversation2.png", "conversation3.png", "conversation4.png",
        "conversation5.png", "conversation6.png", "conversation7.png", "conversation8.png"
    };
    Texture2D* conversationTargets[8] = {
        &conversationTexture1, &conversationTexture2, &conversationTexture3, &conversationTexture4,
        &conversationTexture5, &conversationTexture6, &conversationTexture7, &conversationTexture8
    };
    for (int i = 0; i < 8; i++) {
        *conversationTargets[i] = LoadTexture(conversationFiles[i]);
    }

    keyTexture = LoadTexture("key.png");
    hospitalTexture = LoadTexture("hospital.png");
    libraryTexture = LoadTexture("library.png");
    cdsTexture = LoadTexture("cds.png");
    bookTexture = LoadTexture("book.png");
    mysteryTexture = LoadTexture("mystery.png");
    mysteryTexture2 = LoadTexture("mystery2.png");
    mysteryTexture3 = LoadTexture("mystery3.png");
    classroomTexture = LoadTexture("classroom.png");
    cipherTexture = LoadTexture("cipher.png");
    cipherTexture2 = LoadTexture("cipher2.png");
    usbTexture = LoadTexture("usb.png");
    hallTexture = LoadTexture("hall.png");
    audiTexture = LoadTexture("audi.png");
    professor.LoadTextures();
    hackerTexture = LoadTexture("hacker.png");
    mazeTexture = LoadTexture("maze.png");
    bhaiTexture = LoadTexture("Bhai.png");

    const char* bhaiFiles[11] = {
        "bhai_convo1.png", "bhai_convo2.png", "bhai_convo3.png", "bhai_convo4.png", "bhai_convo5.png",
        "bhai_convo6.png", "bhai_convo7.png", "bhai_convo8.png", "bhai_convo9.png", "bhai_convo10.png",
        "bhai_convo11.png"
    };
    for (int i = 0; i < 11; i++) {
        bhaiConvoTexture[i] = LoadTexture(bhaiFiles[i]);
    }

    const char* apuFiles[7] = {
        "apu_convo1.png", "apu_convo2.png", "apu_convo3.png", "apu_convo4.png", "apu_convo5.png",
        "apu_convo6.png", "apu_convo7.png"
    };
    for (int i = 0; i < 7; i++) {
        apuConvoTexture[i] = LoadTexture(apuFiles[i]);
    }

    const char* hackerFiles[7] = {
        "hacker_convo_1.png", "hacker_convo_2.png", "hacker_convo_3.png", "hacker_convo_4.png",
        "hacker_convo_5.png", "hacker_convo_6.png", "hacker_convo_7.png"
    };
    for (int i = 0; i < 7; i++) {
        hackerConvoTexture[i] = LoadTexture(hackerFiles[i]);
    }

    const char* gardenerFiles[7] = {
        "gardener_convo1.png", "gardener_convo2.png", "gardener_convo3.png", "gardener_convo4.png",
        "gardener_convo5.png", "gardener_convo6.png", "gardener_convo7.png"
    };
    for (int i = 0; i < 7; i++) {
        gardenerConvoTexture[i] = LoadTexture(gardenerFiles[i]);
    }

    const char* professorConvoFiles[14] = {
        "pro1.png", "pro2.png", "pro3.png", "pro4.png", "pro5.png", "pro6.png", "pro7.png",
        "pro8.png", "pro9.png", "pro10.png", "pro11.png", "pro12.png", "pro13.png", "pro14.png"
    };
    for (int i = 0; i < 14; i++) {
        proConvoTexture[i] = LoadTexture(professorConvoFiles[i]);
    }

    pathTexture1 = LoadTexture("path1.png");
    pathTexture2 = LoadTexture("path2.png");

    const char* finalFiles[4] = {"end1.png", "end2.png", "end3.png", "end4.png"};
    for (int i = 0; i < 4; i++) {
        finalTexture[i] = LoadTexture(finalFiles[i]);
    }

    const char* imamFiles[4] = {
        "conversation5.png", "conversation6.png", "conversation7.png", "conversation8.png"
    };
    for (int i = 0; i < 4; i++) {
        imamTexture[i] = LoadTexture(imamFiles[i]);
    }

    gardenerTexture = LoadTexture("gardener.png");
    apuTexture = LoadTexture("apu.png");
    source1={0.0f,0.0f,(float)mysteryTexture2.width,(float)mysteryTexture2.height};


}

void Game::UpdateCamera() {
    if (gameStart) {
        // Center the camera on the menu
        camera.target = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        camera.zoom = 1.1f; // Set the zoom level to fit the menu
    }
    else if (insideClassroom) {
        // Set the camera target and zoom for the classroom
        camera.target = player.position;
        camera.zoom = 1.25f; // Adjust the zoom level to fit the classroom map

        // Constrain the camera within the classroom boundaries
        float minX = 40 + GetScreenWidth() / 2 / camera.zoom;
        float minY = 810 + GetScreenHeight() / 2 / camera.zoom;
        float maxX = 2165 - GetScreenWidth() / 2 / camera.zoom;
        float maxY = 1690 - GetScreenHeight() / 2 / camera.zoom;

        if (camera.target.x < minX) camera.target.x = minX;
        if (camera.target.y < minY) camera.target.y = minY;
        if (camera.target.x > maxX) camera.target.x = maxX;
        if (camera.target.y > maxY) camera.target.y = maxY;
    } else if (insideLibrary) {
        // Set the camera target and zoom for the library
        camera.target = player.position;
        camera.zoom = 1.0f; // Adjust the zoom level for the library

        // Constrain the camera within the library boundaries
        float minX = 100 + GetScreenWidth() / 2 / camera.zoom;
        float minY = 60 + GetScreenHeight() / 2 / camera.zoom;
        float maxX = 2800 - GetScreenWidth() / 2 / camera.zoom; // Increase maxX value
        float maxY = 2100 - GetScreenHeight() / 2 / camera.zoom;

        if (camera.target.x < minX) camera.target.x = minX;
        if (camera.target.y < minY) camera.target.y = minY;
        if (camera.target.x > maxX) camera.target.x = maxX;
        if (camera.target.y > maxY) camera.target.y = maxY;
    } 
    else if (insideHall) {
        // Set the camera target and zoom for the hall
        camera.target = player.position;
        camera.zoom = 1.0f; // Adjust the zoom level for the hall

        // Constrain the camera within the hall boundaries
        float minX = 670 + GetScreenWidth() / 2 / camera.zoom;
        float minY = 600 + GetScreenHeight() / 2 / camera.zoom;
        float maxX = 2500- GetScreenWidth() / 2 / camera.zoom;
        float maxY = 1800 - GetScreenHeight() / 2 / camera.zoom;

        if (camera.target.x < minX) camera.target.x = minX;
        if (camera.target.y < minY) camera.target.y = minY;
        if (camera.target.x > maxX) camera.target.x = maxX;
        if (camera.target.y > maxY) camera.target.y = maxY;
    } 
    else if(mazeActive){
        camera.target = player.position;
        camera.zoom = 1.0f; // Adjust the zoom level for the maze

        // Constrain the camera within the maze boundaries
        float minX = 0 + GetScreenWidth() / 2 / camera.zoom;
        float minY = 0 + GetScreenHeight() / 2 / camera.zoom;
        float maxX = 1920 - GetScreenWidth() / 2 / camera.zoom;
        float maxY = 1080 - GetScreenHeight() / 2 / camera.zoom;

        if (camera.target.x < minX) camera.target.x = minX;
        if (camera.target.y < minY) camera.target.y = minY;
        if (camera.target.x > maxX) camera.target.x = maxX;
        if (camera.target.y > maxY) camera.target.y = maxY;

    }
    else if (insideCDS) {
        // Set the camera target and zoom for the CDS
        camera.target = player.position;
        camera.zoom = 1.1f; // Adjust the zoom level for the CDS

        // Constrain the camera within the CDS boundaries
        float minX = 0 + GetScreenWidth() / 2 / camera.zoom;
        float minY = 0 + GetScreenHeight() / 2 / camera.zoom;
        float maxX = 1800 - GetScreenWidth() / 2 / camera.zoom;
        float maxY = 1080 - GetScreenHeight() / 2 / camera.zoom;

        if (camera.target.x < minX) camera.target.x = minX;
        if (camera.target.y < minY) camera.target.y = minY;
        if (camera.target.x > maxX) camera.target.x = maxX;
        if (camera.target.y > maxY) camera.target.y = maxY;
    } 
    else {
        // Default camera behavior
        camera.target = player.position;

        if (camera.target.x < GetScreenWidth() / 2) camera.target.x = GetScreenWidth() / 2;
        if (camera.target.y < GetScreenHeight() / 2) camera.target.y = GetScreenHeight() / 2;
        if (camera.target.x > map.background.width - GetScreenWidth() / 2) camera.target.x = map.background.width - GetScreenWidth() / 2;
        if (camera.target.y > map.background.height - GetScreenHeight() / 2) camera.target.y = map.background.height - GetScreenHeight() / 2;

        camera.zoom = 1.0f; // Reset the zoom level to default
    }
}


void Game::Run() {
    Initialize();

    if (!initialized) {
        std::cout << "Game failed to initialize properly. Exiting." << std::endl;
        return;
    }

    bool playerPositionUpdated = false; // Flag to ensure the player's position is updated only once

    while (!WindowShouldClose() && GameRunning) {
        if (IsKeyPressed(KEY_F1)) {
            showDebugInfo = !showDebugInfo;
        }

        if (IsKeyPressed(KEY_EQUAL)) {
            camera.zoom += 0.1f;
        }

        if (IsKeyPressed(KEY_MINUS)) {
            camera.zoom -= 0.1f;
            if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        }

        float deltaTime = GetFrameTime();
        
        if (!showConversation && !showMystery && !showMystery2 && !showMystery3 && !showcipher && !showcipher2 && !showHackerConvo && !showGardenerConvo && !showProConvo && !showApuConvo && !showBhaiConvo) { // Only move the player if conversation is NOT showing
            player.Move(deltaTime, insideLibrary, insideClassroom, insideHospital, insideCDS, insideHall);
        }

        
        // Adjust the collision rectangle to better fit the player's sprite
        Rectangle playerCollisionRect = {player.position.x, player.position.y, 25, 25};
        
        if (!insideHospital && !insideCDS && !insideLibrary && !insideClassroom && !insideHall && !insideAudi && !mazeActive) {
            // Perform collision detection and resolution
            ResolvePlayerBuildingCollision(playerCollisionRect, buildings);
            ResolvePlayerIdleCollision(playerCollisionRect, idleRect, conversationPosition, showConversation, conversationStep, firstCollisionOccurred,sequence5);
            if(firstBhaiCollision && !firstApuCollision)
                ResolvePlayerApuCollision(playerCollisionRect, apuRect, apuConversationPosition, showApuConvo, apuConvoStep, firstApuCollision);

            if (keyVisible && !keyFound) {
                ResolvePlayerKeyCollision(playerCollisionRect, keyRect, keyFound);
            }
        }


        if(!insideHospital && !insideCDS && !insideLibrary && !insideClassroom && !insideHall && !insideAudi && !mazeActive){
            ResolvePlayerHospitalCollision(playerCollisionRect, hospitalRect, insideHospital, playerPositionUpdated); // Check for hospital collision
            ResolvePlayerCDSCollision(playerCollisionRect, cdsRect, insideCDS, playerPositionUpdated); // Check for CDS collision
            ResolvePlayerLibraryCollision(playerCollisionRect, libraryRect, insideLibrary, playerPositionUpdated); // Check for library collision
            ResolvePlayerClassroomCollision(playerCollisionRect, classroomRect, insideClassroom, playerPositionUpdated); // Check for library collision	
            ResolvePlayerHallCollision(playerCollisionRect, hallRect, insideHall, playerPositionUpdated); // Check for library collision
            if(mad)
                ResolvePlayerGardenerCollision(playerCollisionRect, gardenerRect, showGardenerConvo, gardenerConvoStep);
            ResolvePlayerAudiCollision(playerCollisionRect, audiRect, insideAudi, playerPositionUpdated); // Check for library collision
            if(firstApuCollision)
                ResolvePlayerMazeCollision(playerCollisionRect, mazeRect, mazeActive, playerPositionUpdated); // Check for library collision
        }

        if (insideHospital) {
            /*DrawRectangleLines(711, 585, 260, 280, BLUE);
            DrawRectangleLines(1272, 227, 240, 135, BLUE);
            DrawRectangleLines(1042, 231, 232, 300, BLUE);
            DrawRectangleLines(752, 229, 208, 60, BLUE);
            DrawRectangleLines(939, 364, 25, 110, BLUE);
            DrawRectangleLines(1050, 425, 450, 25, BLUE);
            DrawRectangleLines(1060, 450, 245, 405, BLUE);
            DrawRectangleLines(690,423,225,50,BLUE);
            */
            InsideHospital(playerCollisionRect, hospitalCollisions);

            //check
            if(IsKeyPressed(KEY_C)){
                insideHospital=false;
                player.position.x=1517;
                player.position.y=382;
                playerCollisionRect.x = 1517; // Update the collision rectangle position
                playerCollisionRect.y = 382;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }
        }


        if(insideCDS){
            //DrawRectangleLines(1390,1670,80,30,BLUE);
            if(ans|| !firstBhaiCollision)
                ResolvePlayerBhaiCollision(playerCollisionRect, bhaiRect, bhaiConversationPosition, showBhaiConvo, bhaiConvoStep,firstBhaiCollision);
           // DrawRectangleLines(1600, 260, 250, 150,BLUE);
            if(IsKeyPressed(KEY_C)){
                insideCDS=false;
                player.position.x=1390;
                player.position.y=1710;
                playerCollisionRect.x = 1390; // Update the collision rectangle position
                playerCollisionRect.y = 1710;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }
        }


        if(insideLibrary){

           
            if(IsKeyPressed(KEY_C)){
                insideLibrary=false;
                player.position.x=1940;
                player.position.y=950;
                playerCollisionRect.x = 1940; // Update the collision rectangle position
                playerCollisionRect.y = 950;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }
            
            InsideMaze(playerCollisionRect, libraryCOllisions);

            if(sequence7){
                FinalCollision(playerCollisionRect, lastRect, Final);
            }
            //check bookfound
            
            if(sequence1 && !bookFound){
                ResolvePlayerBookCollision(playerCollisionRect, bookRect, bookFound);
                if(bookFound){
                    showMystery=true;
                    //mysteryPosition={1500,350};
                }
            }
        }

        if(insideClassroom){

            InsideMaze(playerCollisionRect, classroomCollisions);
            if(IsKeyPressed(KEY_C)){
                insideClassroom=false;
                player.position.x=1990;
                player.position.y=1400;
                playerCollisionRect.x = 1990; // Update the collision rectangle position
                playerCollisionRect.y = 1400;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }

            //check usbFound
            if(!usbFound && sequence3){
                ResolvePlayerUsbCollision(playerCollisionRect, usbRect, usbFound, showcipher);
                
            }

            
        }

        if(insideHall){
            if(sequence4)
                ResolvePlayerHackerCollision(playerCollisionRect, hackerRect, showHackerConvo, hackerConvoStep);
            InsideMaze(playerCollisionRect, hallCollisions);
            if(IsKeyPressed(KEY_C)){
                insideHall=false;
                player.position.x=1860;
                player.position.y=2020;
                playerCollisionRect.x = 1860; // Update the collision rectangle position
                playerCollisionRect.y = 2020;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }
        }

        if(insideAudi){
            InsideAudi(playerCollisionRect, audiCollisions);
            if(sequence2 || sequence6)
                ResolvePlayerProCollision(playerCollisionRect, proRect, showProConvo, proConvoStep, sequence6);
            if(IsKeyPressed(KEY_C)){
                insideAudi=false;
                player.position.x=815;
                player.position.y=1075;
                playerCollisionRect.x = 815; // Update the collision rectangle position
                playerCollisionRect.y = 1075;   // Update the collision rectangle position

                playerPositionUpdated=false;
            }
        }
        if(mazeActive)
        {
            Rectangle ansRect={1810,845,100,80};
            InsideMaze(playerCollisionRect, mazeCollisions);
            ResolvePlayerAnsCollision(playerCollisionRect, ansRect, ans,showAns);
            if(ans)
            {
                //showAns=true;
                mazeActive=false;
                player.position.x=1300;
                player.position.y=1820;
                playerCollisionRect.x = 1300; // Update the collision rectangle position
                playerCollisionRect.y = 1820;

            }
        }


        // Update player position based on the modified collision rectangle
        player.position.x = playerCollisionRect.x;
        player.position.y = playerCollisionRect.y;

        UpdateCamera();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        if (insideHospital) {
            DrawTexture(hospitalTexture, 700, 0, WHITE); // Draw the hospital map
        }
        else if(insideCDS){


            DrawTexture(cdsTexture, 0, 0 , WHITE); // Draw the CDS map

            //Draw BHai
            Rectangle bhaiSource = {0.0f, 0.0f, (float)bhaiTexture.width, (float)bhaiTexture.height};
            Rectangle bhaiDest = {1600, 260, 250, 150}; // Set the destination rectangle to the desired dimensions
            Vector2 bhaiOrigin = {0, 0};
            DrawTexturePro(bhaiTexture, bhaiSource, bhaiDest, bhaiOrigin, 0.0f, WHITE);

        }
        else if(insideLibrary){
            DrawTexture(libraryTexture, 0, 0 , WHITE); // Draw the library map
            if(sequence1 && !bookFound){
                DrawTexture(bookTexture, 1585,364, WHITE);
               // DrawRectangleLines(1585, 364, 32, 32, RED); // Draw the book's collision rectangle
            }

            
            /*if(!bookFound){
                DrawTexture(bookTexture, bookRect.x, bookRect.y, WHITE);
                DrawRectangleLines(bookRect.x, bookRect.y, 32, 32, RED); // Draw the book's collision rectangle
            }*/
        }
        else if(insideClassroom) {
            Rectangle source = {0.0f, 0.0f, (float)classroomTexture.width, (float)classroomTexture.height};
            Rectangle dest = {0, 500, 2200, 1500}; // Set the destination rectangle to the desired dimensions
            Vector2 origin = {0, 0};
            DrawTexturePro(classroomTexture, source, dest, origin, 0.0f, WHITE); // Draw the classroom map using DrawTexturePro
            if(!usbFound && sequence3){
                Rectangle usbSource = {0.0f, 0.0f, (float)usbTexture.width, (float)usbTexture.height};
                Rectangle usbDest = {1728, 1395, 32, 32}; // Set the destination rectangle to 50x50
                DrawTexturePro(usbTexture, usbSource, usbDest, origin, 0.0f, WHITE);
                //DrawRectangleLines(1140,11413,100,40,RED);
            }
        }
        else if(insideHall){
            Rectangle source = {0.0f, 0.0f, (float)hallTexture.width, (float)hallTexture.height};
            Rectangle dest = {-500, 0, 4200, 2500}; // Set the destination rectangle to 1080x1080
            Vector2 origin = {0, 0};
            DrawTexturePro(hallTexture, source, dest, origin, 0.0f, WHITE); // Draw the hall map using DrawTexturePro
          
            //draw hacker
            Rectangle hackerSource = {0.0f, 0.0f, (float)hackerTexture.width, (float)hackerTexture.height};
            Rectangle hackerDest = {830,954,210,140}; // Set the destination rectangle to 50x50
            DrawTexturePro(hackerTexture, hackerSource, hackerDest, origin, 0.0f, WHITE);
        
        }
        else if(insideAudi){
            //DrawTexture(audiTexture, 0, 0 , WHITE); // Draw the audi map
            Rectangle source = {0.0f, 0.0f, (float)audiTexture.width, (float)audiTexture.height};
            Rectangle dest = {0, 0, 2000, 1800}; // Set the destination rectangle to the desired dimensions
            Vector2 origin = {0, 0};
            DrawTexturePro(audiTexture, source, dest, origin, 0.0f, WHITE); // Draw the audi map using DrawTexturePro

        //     Rectangle source2 = {0.0f, 0.0f, (float)proTexture.width, (float)proTexture.height};
        //     Rectangle dest2 = {930, 760, 450, 300}; // Set the destination rectangle to the desired dimensions
        //     Vector2 origin2 = {0, 0};
        //     DrawTexturePro(proTexture, source2, dest2, origin2, 0.0f, WHITE); // Draw the audi map using DrawTexturePro
        //    // DrawRectangleLines(1050,870,120,120,RED);
            professor.Draw(professor.position);
        }
        else if(mazeActive){
            //DrawTexture
            Rectangle source = {0.0f, 0.0f, (float)mazeTexture.width, (float)mazeTexture.height};
            Rectangle dest = {0, 0, 1920, 1080}; // Set the destination rectangle to the desired dimensions
            Vector2 origin = {0, 0};
            DrawTexturePro(mazeTexture, source, dest, origin, 0.0f, WHITE); // Draw the audi map using DrawTexturePro
        }
        else if(gameStart){

            Rectangle source = {0.0f, 0.0f, (float)menu[0].width, (float)menu[0].height};
            Rectangle dest = {-20, -20, (float)GetScreenWidth()+20, (float)GetScreenHeight()+20};
            
            Vector2 mousePos = GetMousePosition();
            cout << "Mouse Position: " << mousePos.x << " " << mousePos.y << endl;
            if(CheckCollisionPointRec(mousePos, startRect))
            {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    gameStart=false;
                    playerDraw=true;
                }
                DrawTexturePro(menu[1], source, dest, {0, 0}, 0.0f, WHITE);
                
            }
            else if (CheckCollisionPointRec(mousePos, exitRect))
            {   
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    GameRunning=false;
                }
                DrawTexturePro(menu[2], source, dest, {0, 0}, 0.0f, WHITE);
               
            }
            else
            {
                DrawTexturePro(menu[0], source, dest, {0, 0}, 0.0f, WHITE);
            }
        
            if(IsKeyPressed(KEY_ENTER)){
                gameStart=false;
                playerDraw=true;
            }
        }
        else {
            map.Draw(cameraPosition); // Draw the main map
        }
        if(playerDraw){
            player.Draw(cameraPosition);
    }


        
       
       //map idle draw
        if (!insideHospital && !insideCDS && !insideLibrary && !insideClassroom && !insideHall && !insideAudi && !mazeActive && playerDraw) {
           // DrawTexturePro(Texture, source, {idleRect.x, idleRect.y, idleRect.width, idleRect.height}, {idleRect.width / 2, idleRect.height / 2}, 0.0f, WHITE);
            idle.Draw(cameraPosition);
            Rectangle gardenerSource = {0.0f, 0.0f, (float)gardenerTexture.width, (float)gardenerTexture.height};
            Rectangle gardenerDest = {1075, 1800, 100, 100}; // Set the destination rectangle to the desired dimensions
            Vector2 gardenerOrigin = {0, 0};
            DrawTexturePro(gardenerTexture, gardenerSource, gardenerDest, gardenerOrigin, 0.0f, WHITE);

            //Apu Drawing
            Rectangle apuSource = {0.0f, 0.0f, (float)apuTexture.width, (float)apuTexture.height};
            Rectangle apuDest = {apuRect.x, apuRect.y-50, apuRect.width+50, apuRect.height+50}; // Set the destination rectangle to the desired dimensions
            Vector2 apuOrigin = {0, 0};
            DrawTexturePro(apuTexture, apuSource, apuDest, apuOrigin, 0.0f, WHITE);
        }

        if(showMystery){
            DrawTexture(mysteryTexture, 700,50, WHITE);
        }

        if(showMystery2){
            sequence2=true;
           
           // DrawTexturePro(mysteryTexture2, source1, {1350,250, (float)mysteryTexture2.width+120,(float) mysteryTexture2.height+150}, {0,0}, 0.0f, WHITE);
            Rectangle source = {0.0f, 0.0f, (float)mysteryTexture2.width, (float)mysteryTexture2.height};
            Rectangle dest = {700, 50, 1920, 1080}; // Set the destination rectangle to 1920x1080
            Vector2 origin = {0, 0};
            DrawTexturePro(mysteryTexture2, source, dest, origin, 0.0f, WHITE);
        }

        if(showMystery3){
            DrawTexture(mysteryTexture3, 700,50, WHITE);
        }


        //cipher
        if(showcipher){
            DrawTexture(cipherTexture, 600,770, WHITE);
            if(IsKeyPressed(KEY_ENTER)){
                showcipher=false;
                showcipher2=true;
            }
        }
        else if(showcipher2){
            DrawTexture(cipherTexture2, 600,770, WHITE);
            if(IsKeyPressed(KEY_ENTER)){
                showcipher2=false;
                sequence4=true;
            }
        }

        
        
        
        //drawing rectangle for collision check
        /*DrawRectangleLines(idleRect.x, idleRect.y, idleRect.width, idleRect.height, RED);
        DrawRectangleLines(422,640,240,550, RED);
        DrawRectangleLines(240,2051,1330,200, RED);
        DrawRectangleLines(1185,855,220,250, RED);
        DrawRectangleLines(660,640,500,100, RED);

        DrawRectangleLines(1274,640,370,200,RED);
        DrawRectangleLines(1464,735,180,350,RED);
        DrawRectangleLines(760, 1190,550,225,RED);
        DrawRectangleLines(1473,1200,200,225,RED);
        DrawRectangleLines(1695, 1530, 500, 460,RED);
        DrawRectangleLines(1260, 1496, 340, 190,RED);
        DrawRectangleLines(1733, 1115, 530, 240,RED);
        DrawRectangleLines(1918, 1080, 280, 40,RED);
        DrawRectangleLines(1722, 634, 500, 300,RED);
        DrawRectangleLines(1399, 56, 270, 270,RED);
        DrawRectangleLines(100, 70, 550, 280,RED);
        DrawRectangleLines(420,1190, 240, 215,RED);
        DrawRectangleLines(672, 830, 360, 210,RED);
        DrawRectangleLines(1338, 1825, 200, 170,RED);
        DrawRectangleLines(1335, 1820, 210, 180,GREEN);
        DrawRectangleLines(1395, 50, 280, 280,GREEN);
        DrawRectangleLines(1390,1670,80,30,GREEN);
        DrawRectangleLines(1940,914,150,30,GREEN);
        DrawRectangleLines(1060,1800,100,100,GREEN);
        DrawRectangleLines(806,1040,30,30,GREEN);
        */
       //DrawRectangleLines(1750,500,500,500,GREEN);

        // If conversation is active, draw the appropriate image
        if (showConversation) {
            if (conversationStep == 0) {
                DrawTexture(conversationTexture1, conversationPosition.x+60, conversationPosition.y-50, WHITE);
            } else if (conversationStep == 1) {
                DrawTexture(conversationTexture2, conversationPosition.x+60, conversationPosition.y-50, WHITE);
            } else if (conversationStep == 2) {
                if (keyFound) {
                    DrawTexture(conversationTexture4, conversationPosition.x+60, conversationPosition.y-50, WHITE);
                } else {
                    DrawTexture(conversationTexture3, conversationPosition.x+60, conversationPosition.y-50, WHITE);
                }
            } else if (conversationStep == 3) {
                DrawTexture(conversationTexture4, conversationPosition.x+60, conversationPosition.y-50, WHITE);
            }
            else if(conversationStep==5)
                DrawTexture(conversationTexture5, conversationPosition.x-250, conversationPosition.y-320, WHITE);
            else if(conversationStep==6)
                DrawTexture(conversationTexture6, conversationPosition.x-250, conversationPosition.y-320, WHITE);
            else if(conversationStep==7)
                DrawTexture(conversationTexture7, conversationPosition.x-450, conversationPosition.y-420, WHITE);
            else if(conversationStep==8)
                DrawTexture(conversationTexture8, conversationPosition.x-250, conversationPosition.y-320, WHITE);
        }

        //apu
        if (showApuConvo) {
            DrawTexture(apuConvoTexture[apuConvoStep], apuConversationPosition.x + 60, apuConversationPosition.y - 50, WHITE);
            
        }

        if(showBhaiConvo){
            DrawTexture(bhaiConvoTexture[bhaiConvoStep], bhaiConversationPosition.x-400, bhaiConversationPosition.y -50, WHITE);
        }

        if(showAns){
            DrawTexture(pathTexture1,500,1200,WHITE);
        }

        if(showmap ){
            DrawTexture(pathTexture2, 500, 1200, WHITE);
        }

        if(showHackerConvo){
            DrawTexture(hackerConvoTexture[hackerConvoStep], 350, 450, WHITE);
            sequence5=true;
        }

        if(showGardenerConvo){
            sequence1=true;
            DrawTexture(gardenerConvoTexture[gardenerConvoStep], 730, 1300, WHITE);
        }


        if(showProConvo){
            sequence3=true;	
            // DrawTexture(proConvoTexture[proConvoStep], 900, 255, WHITE);
            professor.DrawConversation(professor.proConvoStep,{900,255});
        }
        // Draw the key if it is visible and has not been found
        if (keyVisible && !keyFound) {
            DrawTexture(keyTexture, keyRect.x, keyRect.y, WHITE);
           // DrawRectangleLines(keyRect.x, keyRect.y, 32, 32, RED); // Draw the key's collision rectangle
        }

        if(Final){
            DrawTexture(finalTexture[finalStep], 1000, 0, WHITE);
        }
        

        EndMode2D();

        if (showDebugInfo) {
            DrawText("IUT Chronicles - RPG", 10, 10, 20, BLACK);
            DrawText(TextFormat("FPS: %d", GetFPS()), 10, 40, 16, BLACK);
           // DrawText(TextFormat("Player position: (%.2f, %.2f)", player.position.x, player.position.y), GetScreenWidth() - 300, 10, 20, BLACK);
        }

        // Print the current state of showConversation and insideHospital at the top-right corner
       /* DrawText(TextFormat("Conversation: %s", showConversation ? "ON" : "OFF"), GetScreenWidth() - 200, 50, 20, BLACK);
        DrawText(TextFormat("Inside Hospital: %s", insideHospital ? "YES" : "NO"), GetScreenWidth() - 200, 80, 20, BLACK);
        DrawText(TextFormat("Inside CDS: %s", insideCDS ? "YES" : "NO"), GetScreenWidth() - 200, 110, 20, BLACK);
        DrawText(TextFormat("Mad: %s", mad ? "YES" : "NO"), GetScreenWidth() - 200, 140, 20, BLACK);
        DrawText(TextFormat("Inside Classroom: %s", insideClassroom ? "YES" : "NO"), GetScreenWidth() - 200, 170, 20, BLACK);
        DrawText(TextFormat("Pro: %s", showProConvo ? "YES" : "NO"), GetScreenWidth() - 200, 200, 20, BLACK);
        //draw ans
        DrawText(TextFormat("Ans: %s", ans ? "YES" : "NO"), GetScreenWidth() - 200, 230, 20, BLACK);

        //drawmazeActive
        DrawText(TextFormat("Maze: %s", mazeActive ? "YES" : "NO"), GetScreenWidth() - 200, 260, 20, BLACK);
        //draw firstBhaiCollision
        DrawText(TextFormat("Bhai: %s", firstBhaiCollision ? "YES" : "NO"), GetScreenWidth() - 200, 290, 20, BLACK);
        //draw showmap
        DrawText(TextFormat("Map: %s", showmap ? "YES" : "NO"), GetScreenWidth() - 200, 320, 20, BLACK);
        //drawapuconvostep
        //DrawText(TextFormat("Apu: %d", apuConvoStep), GetScreenWidth() - 200, 260, 20, BLACK);
        //DrawText(TextFormat("Health: %d", healthSystem.GetHealth()), GetScreenWidth() - 200, 260, 20, BLACK);
        */
        
        // If Enter is pressed, switch to the next conversation step or hide the conversation
        if (showConversation && IsKeyPressed(KEY_ENTER)) {
            if (conversationStep == 0) {
                conversationStep = 1;
            } else if (conversationStep == 1) {
                showConversation = false;
                conversationStep = 2;
                keyVisible = true; // Make the key visible
            } else if (conversationStep == 2) {
                showConversation = false;
                conversationStep = 3;
            } else if (conversationStep == 3) {
                showConversation = false;
                conversationStep = 4;
            }
            else if(conversationStep ==5)
                conversationStep=6;
            else if (conversationStep == 6) 
                conversationStep = 7;
            else if(conversationStep == 7){
                conversationStep = 8;
                sequence6=true;
                showConversation=false;
            }
            
            
        }

        //apu
        if (showApuConvo && IsKeyPressed(KEY_ENTER)) {
            apuConvoStep++;
            if (apuConvoStep == 7) {
                firstApuCollision =true;
                showApuConvo = false;
            }
        }

        if(showBhaiConvo && IsKeyPressed(KEY_ENTER)){
            bhaiConvoStep++;
            if(ans && bhaiConvoStep==11){
                firstBhaiCollision=false;
                mad=true;
                showBhaiConvo=false;

            }
            else if(!ans && bhaiConvoStep==8){
                showBhaiConvo=false;
            }
        }

        if (showAns && IsKeyPressed(KEY_ENTER)) {
            showmap = true;
            showAns = false;
            
        }

        if (showmap && IsKeyPressed(KEY_ENTER)) {
            showmap = false;
            show = true;
        }

        if(showHackerConvo && IsKeyPressed(KEY_ENTER)){
            hackerConvoStep++;
            if(hackerConvoStep==7){
                showHackerConvo=false;  
            }
        }

        if(showGardenerConvo && IsKeyPressed(KEY_ENTER)){
            gardenerConvoStep++;
            if(gardenerConvoStep==7){
                showGardenerConvo=false;
            }
        }

        if(showProConvo && IsKeyPressed(KEY_ENTER)){
            professor.proConvoStep++;
            if(sequence6 && professor.proConvoStep==14){
                sequence7=true;
                showProConvo=false;
            }
            
            else if(!sequence6 && professor.proConvoStep==7){
                showProConvo=false;
            }
        }

        // If the key is found, hide it
        if(showMystery && IsKeyPressed(KEY_ENTER)){
            showMystery=false;
            showMystery2=true;
        }
        else if(showMystery2 && IsKeyPressed(KEY_ENTER)){
            showMystery2=false;
            showMystery3=true;
        }
        else if(showMystery3 && IsKeyPressed(KEY_ENTER)){
            showMystery3=false;
        }



        //Final Reveal
        if(Final){
           
            if(IsKeyPressed(KEY_ENTER)){
                finalStep++;
                //if(finalStep==4)
                  //  GameRunning=false;
            }
        }


        EndDrawing();
    }

    map.Unload();
    player.Unload();
    idle.Unload(); // Unload the idle character texture
    
    UnloadTexture(conversationTexture1); // Unload the first conversation texture
    UnloadTexture(conversationTexture2); // Unload the second conversation texture
    UnloadTexture(conversationTexture3); // Unload the third conversation texture
    UnloadTexture(conversationTexture4); // Unload the fourth conversation texture
    UnloadTexture(keyTexture); // Unload the key texture
    UnloadTexture(hospitalTexture); // Unload the hospital texture
    UnloadTexture(libraryTexture); // Unload the library texture
    UnloadTexture(cdsTexture); // Unload the CDS texture
    UnloadTexture(bookTexture); // Unload the book texture
    UnloadTexture(mysteryTexture); // Unload the mystery texture
    UnloadTexture(mysteryTexture2); // Unload the mystery2 texture
    UnloadTexture(mysteryTexture3); // Unload the mystery3 texture
    UnloadTexture(classroomTexture); // Unload the classroom texture
    UnloadTexture(usbTexture); // Unload the USB texture
    UnloadTexture(cipherTexture); // Unload the cipher texture
    UnloadTexture(cipherTexture2); // Unload the cipher2 texture
    UnloadTexture(hallTexture); // Unload the hall texture
    UnloadTexture(hackerTexture);
    UnloadTexture(gardenerTexture);
    UnloadTexture(audiTexture);
    UnloadTexture(bhaiTexture);
    //UnloadTexture(proTexture);
    professor.UnloadTextures();
    UnloadTexture(mazeTexture);
    UnloadTexture(apuTexture);
    UnloadTexture(conversationTexture5);
    UnloadTexture(conversationTexture6);
    UnloadTexture(conversationTexture7);
    UnloadTexture(conversationTexture8);
    UnloadTexture(pathTexture1);
    UnloadTexture(pathTexture2);

    for(int i=0; i<3; i++){
        UnloadTexture(menu[i]);
    }
    
    for(int i=0; i<11; i++){
        UnloadTexture(bhaiConvoTexture[i]);
    }
    
    for(int i=0; i<7; i++){
        UnloadTexture(apuConvoTexture[i]);
    }

    for(int i=0;i<14;i++){
        UnloadTexture(proConvoTexture[i]);
    }
    for (int i = 0; i < 7; i++) {
        UnloadTexture(hackerConvoTexture[i]);
    }
    for (int i = 0; i < 7; i++) {
        UnloadTexture(gardenerConvoTexture[i]);
    }
    for (int i = 0; i < 4; i++) {
        UnloadTexture(imamTexture[i]);
    }
    for (int i = 0; i < 4; i++) {
        UnloadTexture(finalTexture[i]);
    }
    CloseWindow();
}