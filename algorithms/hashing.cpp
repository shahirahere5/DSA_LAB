#include &lt;iostream&gt;
using namespace std;
const int SIZE = 10;
class Node{
public:
string key;
string value;
Node* next;
Node(string k, string v){
key = k;
value = v;
next =NULL;
}

};
class HashTable{
public:
Node** table;
HashTable() {
table = new Node*[SIZE];
for (int i = 0; i &lt; SIZE; i++)
table[i] = NULL;
}
int hashFunction(string key){
int sum = 0;
for(int i=0; i&lt; key.length();i++){
sum += key[i];

}
return sum%SIZE;
}
void insert(string key, string value){
int index = hashFunction(key);
Node* newNode = new Node(key, value);
if(table[index] == NULL){
table[index] = newNode;

return;
}else{
Node* temp = table[index];
while(temp-&gt;next != NULL){
temp=temp-&gt;next;
}
temp-&gt;next = newNode;
}
}
void display(){
for(int i=0;i&lt;SIZE;i++){
cout &lt;&lt; i &lt;&lt; &quot;: &quot;;
Node* temp=table[i];
while(temp != NULL){
cout &lt;&lt; &quot;(&quot; &lt;&lt; temp-&gt;key &lt;&lt; &quot;, &quot; &lt;&lt; temp-&gt;value &lt;&lt; &quot;) -&gt; &quot;;
temp=temp-&gt;next;
}
cout &lt;&lt; &quot;NULL&quot; &lt;&lt; endl;
}
}

};
int main() {
HashTable myhash;
myhash.insert(&quot;A&quot;, &quot;aaaaa&quot;);
myhash.insert(&quot;B&quot;, &quot;bbbbb&quot;);
myhash.insert(&quot;C&quot;, &quot;ccccc&quot;);
myhash.insert(&quot;A&quot;, &quot;zzzzz&quot;);
myhash.display();
return 0;
}




#include &lt;iostream&gt;
using namespace std;
const int SIZE = 10;
class Node{
public:
string key;
string value;
Node* next;
Node(string k, string v){
key = k;
value = v;
next =NULL;
}

};
class ASCIIDictionary{
private:
Node** table;
public:
ASCIIDictionary(){
table = new Node*[SIZE];
for(int i = 0;i&lt;SIZE;i++){
table[i] = NULL;
}

}
int hashFunction(string key){

int sum = 0;
for(int i=0; i&lt; key.length();i++){
sum += key[i];

}
return sum%SIZE;
}
void addRecord(string key, string value){
int index = hashFunction(key);
Node* newNode = new Node(key, value);
if(table[index] == NULL){
table[index] = newNode;
return;
}else{
Node* temp = table[index];
while(temp-&gt;next != NULL){
temp=temp-&gt;next;
}
temp-&gt;next = newNode;
}
cout &lt;&lt; &quot;Added (&quot; &lt;&lt; key &lt;&lt; &quot;, &quot; &lt;&lt; value &lt;&lt; &quot;) at index &quot; &lt;&lt; index &lt;&lt; endl;
}
void searchWord(string key){
int index = hashFunction(key);
Node* temp = table[index];
while (temp != NULL) {
if (temp-&gt;key == key) {
cout &lt;&lt; &quot;Found (&quot; &lt;&lt; temp-&gt;key &lt;&lt; &quot;, &quot; &lt;&lt; temp-&gt;value &lt;&lt; &quot;) at index &quot; &lt;&lt; index &lt;&lt; endl;
return;
}
temp = temp-&gt;next;
}
cout &lt;&lt; &quot;Error: &#39;&quot; &lt;&lt; key &lt;&lt; &quot;&#39; not found in dictionary.&quot; &lt;&lt; endl;

}
void printDictionary() {
for (int i = 0; i &lt; SIZE; i++) {
cout &lt;&lt; i &lt;&lt; &quot;: &quot;;
Node* temp = table[i];

while (temp != NULL) {
cout &lt;&lt; &quot;(&quot; &lt;&lt; temp-&gt;key &lt;&lt; &quot;, &quot; &lt;&lt; temp-&gt;value &lt;&lt; &quot;) -&gt; &quot;;
temp = temp-&gt;next;
}
cout &lt;&lt; &quot;NULL&quot; &lt;&lt; endl;
}
}
};
int main() {
ASCIIDictionary dict;
dict.addRecord(&quot;A&quot;, &quot;Apple&quot;);
dict.addRecord(&quot;B&quot;, &quot;Banana&quot;);
dict.addRecord(&quot;C&quot;, &quot;Cherry&quot;);
dict.addRecord(&quot;A&quot;, &quot;Apricot&quot;);
dict.addRecord(&quot;AB&quot;, &quot;FASTNU&quot;);
cout &lt;&lt; endl;
cout &lt;&lt; &quot;Searching for &#39;B&#39;:\n&quot;;
dict.searchWord(&quot;B&quot;);
cout &lt;&lt; endl;
cout &lt;&lt; &quot;Searching for &#39;D&#39;:\n&quot;;
dict.searchWord(&quot;D&quot;);
cout &lt;&lt; endl;
cout &lt;&lt; &quot;Complete Dictionary:\n&quot;;
dict.printDictionary();
return 0;
}


#include &lt;iostream&gt;
#include &lt;list&gt;
using namespace std;
const int SIZE = 10;
class HashTable {
public:
    list&lt;pair&lt;string,string&gt;&gt; table[SIZE];
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % SIZE;
    }
    void insert(string key, string value) {
        int index = hashFunction(key);
        for (auto &amp;p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }
    void removeKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it-&gt;first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
    void search(string key) {
        int index = hashFunction(key);
        for (auto &amp;p : table[index]) {
            if (p.first == key) {
                cout &lt;&lt; key &lt;&lt; &quot;: &quot; &lt;&lt; p.second &lt;&lt; endl;
                return;
            }

        }
        cout &lt;&lt; &quot;Not found&quot; &lt;&lt; endl;
    }
    void display() {
        for (int i = 0; i &lt; SIZE; i++) {
            cout &lt;&lt; i &lt;&lt; &quot;: &quot;;
            for (auto &amp;p : table[i])
                cout &lt;&lt; &quot;(&quot; &lt;&lt; p.first &lt;&lt; &quot;, &quot; &lt;&lt; p.second &lt;&lt; &quot;) -&gt; &quot;;
            cout &lt;&lt; &quot;NULL&quot; &lt;&lt; endl;
        }
    }
};
int main() {
    HashTable h;
    h.insert(&quot;A&quot;,&quot;aaaaa&quot;);
    h.insert(&quot;B&quot;,&quot;bbbbb&quot;);
    h.insert(&quot;C&quot;,&quot;ccccc&quot;);
    h.insert(&quot;A&quot;,&quot;zzzzz&quot;);
    h.display();
    h.search(&quot;B&quot;);
    h.removeKey(&quot;B&quot;);
    h.display();
}



#include &lt;iostream&gt;
using namespace std;
class Hash {
public:
    int arr[10];
    Hash() {
        for(int i=0;i&lt;10;i++)
            arr[i] = -1;
    }
    int hashFunction(int key) {
        return key % 10;
    }
    void insert(int key) {

        int index = hashFunction(key);
        while(arr[index] != -1)
            index = (index + 1) % 10;
        arr[index] = key;
    }
    void removeKey(int key) {
        int index = hashFunction(key);
        int start = index;
        while(arr[index] != -1) {
            if(arr[index] == key) {
                arr[index] = -1;
                return;
            }
            index = (index + 1) % 10;
            if(index == start) break;
        }
    }
    void search(int key) {
        int index = hashFunction(key);
        int start = index;
        while(arr[index] != -1) {
            if(arr[index] == key) {
                cout &lt;&lt; key &lt;&lt; &quot; found&quot; &lt;&lt; endl;
                return;
            }
            index = (index + 1) % 10;
            if(index == start) break;
        }
        cout &lt;&lt; key &lt;&lt; &quot; not found&quot; &lt;&lt; endl;
    }
    void display() {
        for(int i=0;i&lt;10;i++)
            if(arr[i] != -1)
                cout &lt;&lt; arr[i] &lt;&lt; &quot; &quot;;
        cout &lt;&lt; endl;
    }
};
int main() {
    Hash h;
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);

    h.display();
    cout &lt;&lt; &quot;Remove 4&quot; &lt;&lt; endl;
    h.removeKey(4);
    h.display();
    h.search(5);
    h.search(6);
}



#include &lt;iostream&gt;
using namespace std;
const int SIZE = 20;
class Node {
public:
    int a, b;
    Node* next;
    Node(int x, int y) {
        a = x;
        b = y;
        next = NULL;
    }
};
class HashTable {
public:
    Node* table[SIZE];
    HashTable() {
        for(int i=0;i&lt;SIZE;i++)
            table[i] = NULL;
    }

    int hashFunction(int sum) {
        return sum % SIZE;
    }
    bool insertPair(int x, int y) {
        int sum = x + y;
        int index = hashFunction(sum);
        Node* temp = table[index];
        while(temp != NULL) {
            if(temp-&gt;a != x &amp;&amp; temp-&gt;b != x &amp;&amp;
               temp-&gt;a != y &amp;&amp; temp-&gt;b != y) {
                cout &lt;&lt; &quot;(&quot; &lt;&lt; temp-&gt;a &lt;&lt; &quot;, &quot; &lt;&lt; temp-&gt;b &lt;&lt; &quot;) and (&quot;
                     &lt;&lt; x &lt;&lt; &quot;, &quot; &lt;&lt; y &lt;&lt; &quot;)&quot; &lt;&lt; endl;
                return true;
            }
            temp = temp-&gt;next;
        }
        Node* newNode = new Node(x, y);
        newNode-&gt;next = table[index];
        table[index] = newNode;
        return false;
    }
};
bool findPairs(int arr[], int n) {
    HashTable h;
    for(int i=0;i&lt;n;i++) {
        for(int j=i+1;j&lt;n;j++) {
            if(h.insertPair(arr[i], arr[j]))
                return true;
        }
    }
    cout &lt;&lt; &quot;No pairs found&quot; &lt;&lt; endl;
    return false;
}
int main() {
    int a1[] = {3, 4, 7, 1, 2, 9, 8};
    int a2[] = {3, 4, 7, 1, 12, 9};
    int a3[] = {65, 30, 7, 90, 1, 9, 8};

    findPairs(a1,7);
    findPairs(a2,6);
    findPairs(a3,7);
}



#include &lt;iostream&gt;
using namespace std;
class StudentHashTable {
public:
    int rolls[15];
    string names[15];
    StudentHashTable() {
        for(int i=0;i&lt;15;i++) {
            rolls[i] = -1;
            names[i] = &quot;&quot;;
        }
    }
    int hashFunction(int roll) {
        return roll % 15;
    }
    void InsertRecord(int roll, string name) {
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt &lt; 15) {
            int newIndex = (index + attempt*attempt) % 15;
            if(rolls[newIndex] == -1) {
                rolls[newIndex] = roll;
                names[newIndex] = name;
                return;

            }
            attempt++;
        }
        cout &lt;&lt; &quot;Table full, cannot insert\n&quot;;
    }
    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt &lt; 15) {
            int newIndex = (index + attempt*attempt) % 15;
            if(rolls[newIndex] == roll) {
                cout &lt;&lt; names[newIndex] &lt;&lt; endl;
                return;
            }
            if(rolls[newIndex] == -1) break;
            attempt++;
        }
        cout &lt;&lt; &quot;Record not found&quot; &lt;&lt; endl;
    }
};
int main() {
    StudentHashTable s;
    s.InsertRecord(20, &quot;Ali&quot;);
    s.InsertRecord(35, &quot;Sara&quot;);
    s.InsertRecord(50, &quot;Ahmed&quot;);
    s.SearchRecord(35);
    s.SearchRecord(99);
}
