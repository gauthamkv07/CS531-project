#ifndef ITEM_STRUCTURES
#define ITEM_STRUCTURES

struct Laptops
{ 
    int id;
    char brandName[25];
    char processorBrand[25];
    char processorModel[25];
    char graphicCardBrand[25];
    char graphicCardModel[25];
    char operatingSystem[25];
    char RAM[25];
    char storage[25];
    float price;
};

struct Cameras
{ 
    int id;
    char brandName[25];
    char ModelNumber[25];
    char cameraType[25];
    char color[25];
    char sensorType[25];  //COMS, Live MOS
    char sensorSize[25]; // Four Thirds System, APS-C
    char effectivePixels[25]; // 16.1 megapixels
    char storage[25];  // 125 GB
    float width;
    float height;
    float depth;
    float price;
};

struct Phones
{ 
    int id;
    char brandName[25];
    char ModelNumber[25];
    char storage[25];  // 125 GB
    char color[25];
    float width;
    float height;
    float price;
};

struct Watches
{ 
    int id;
    char brandName[25];
    char ModelNumber[25];
    char type[25];  // mechanical, quartz, automatical
    char color[25];
    float weight;
    float price;
};

struct Refrigerators
{ 
    int id;
    char brandName[25];
    char ModelNumber[25];
    char doorStyle[25];  // frech door, side-by-side
    char color[25];
    float width;
    float height;
    float depth;
    float price;
};
#endif