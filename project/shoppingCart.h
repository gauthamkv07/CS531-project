//cart structure
struct cart{
    int itemId;
    char name[25];
    double price;
    int qty;
    struct cart *next;
};