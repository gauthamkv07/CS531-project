//cart structure
struct cart{
    int itemId;
    char name[25];
    char prodName[200];
    float price;
    int qty;
    struct cart *next;
};