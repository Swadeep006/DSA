class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};
class LRUCache {
    int capacity;
    unordered_map<int, Node*> cacheMap;
    DLL dll;

public:
    LRUCache(int capacity) { this->capacity = capacity; }
    int get(int key) {
        if (cacheMap.contains(key)) {
            Node* newNode = cacheMap[key];
            dll.removeNode(newNode);
            dll.insertAtHead(newNode);
            return newNode->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.contains(key)) {
            Node* existingNode = cacheMap[key];
            existingNode->value = value;
            dll.removeNode(existingNode);
            dll.insertAtHead(existingNode);
        } else {
            if (cacheMap.size() == capacity) {
                Node* lru = dll.tail->prev;
                cacheMap.erase(lru->key);
                dll.removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            dll.insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */