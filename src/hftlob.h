#ifndef HFTLOB_H_
#define HFTLOB_H_
/**
 * CUSTOM STRUCTS
 */

typedef struct Order{
    int tid;
    unsigned buyOrSell;
    float shares;
    int limit;
    int entryTime;
    int eventTime;
    struct Order *nextOrder;
    struct Order *prevOrder;
    struct Limit *parentLimit;
} Order;

typedef struct Limit{
    float limitPrice;
    float size;
    float totalVolume;
    int orderCount;
    struct Limit *parent;
    struct Limit *leftChild;
    struct Limit *rightChild;
    struct Order *headOrder;
    struct Order *tailOrder;
} Limit;

typedef struct QItem{
    Limit *limit;
    struct QItem *previous;
} QItem;

typedef struct Queue{
    QItem *head;
    QItem *tail;
} Queue;

/**
 * QUEUE FUNCTIONS
 */

void
pushToQueue(Queue *q, Limit *limit);

Limit*
popFromQueue(Queue *q);

int
queueIsEmpty(Queue *q);

/**
 * ORDER FUNCTIONS
 */

int
pushOrder(Limit *limit, Order *new_order);

int
popOrder(Limit *limit);

/**
 * BINARY SEARCH TREE FUNCTIONS
 */

Limit*
createRoot(void);

int
addNewLimit(Limit *root, Limit *limit);

void
replaceLimitInParent(Limit *limit, Limit *newLimit);

int
removeLimit(Limit *limit);

/**
 * BINARY SEARCH TREE BALANCING FUNCTIONS
 */

void
balanceBranch(Limit *limit);

void
rotateLeftLeft(Limit *limit);

void
rotateLeftRight(Limit *limit);

void
rotateRightRight(Limit *limit);

void
rotateRightLeft(Limit *limit);


/**
 * CONVENIENCE FUNCTIONS FOR BST OPERATIONS
 */

int
limitExists(Limit *root, float value);

int
limitIsRoot(Limit *limit);

int
hasGrandpa(Limit *limit);

Limit*
getGrandpa(Limit *limit);

Limit*
getMinimumLimit(Limit *limit);

Limit*
getMaximumLimit(Limit *limit);

int
getHeight(Limit *limit);

int
getBalanceFactor(Limit *limit);


/**
 * CuTest Functions
 * */

void RunAllTests(void);

#endif