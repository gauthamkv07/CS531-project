//cart structure
struct cart{
    int itemId;
    char name[25];
    char prodName[25];
    float price;
    int qty;
    struct cart *next;
};