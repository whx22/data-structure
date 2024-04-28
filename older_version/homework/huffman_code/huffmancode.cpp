#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define MaxSize 256

typedef struct
{
    char ch;
    string huffman_code;
    int weight;
    int parent, lchild, rchild;
    double weightPercentage;
} HuffmanTreeNode; //定义huffmanTree结点

typedef struct
{
    HuffmanTreeNode data[MaxSize];
    int charKind;
    int size;
} HuffmanTreeTable; //定义huffmanTreeTable

void UserCin(char* str_char);
void InitTable(HuffmanTreeTable& HTT);
void Select(const HuffmanTreeTable& HTT, int n, int& s1, int& s2);
void CreateHuffmanTreeTable1(HuffmanTreeTable& HTT);
void CreateHuffmanTreeTable2(HuffmanTreeTable& HTT);
void Encode(const HuffmanTreeTable& HTT);
void Decode(const HuffmanTreeTable& HTT);
void PrintHuffmanTreeTable(const HuffmanTreeTable& HTT);
void WriteTxt(void);
void ReadTxt(void);
void WriteBinary(const HuffmanTreeTable& HTT);
void ReadBinary(HuffmanTreeTable& HTT);


//接送用户输入字符串
void UserCinChar(char* str_char)
{
    cin.get(str_char, 10000);
}

//接受用户输入哈夫曼编码
void UserCinBinary(char* str_binary)
{
    cin.get(str_binary, 10000);
}

//初始化哈夫曼树表
void InitTable(HuffmanTreeTable& HTT)
{
    HTT.charKind = 0;
    HTT.size = 0;
}

//在当前的HT[n]（1<=n<=i-1）中
//选出两个(parent == 0)且(weight最小)的结点并返回其下标s1，s2
void Select(const HuffmanTreeTable& HTT, int n, int& s1, int& s2)
{
    if (n < 2)
        return;
    int w1 = -1, w2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (HTT.data[i].parent == 0)
        {
            if (w1 == -1 || HTT.data[i].weight <= w1)
            {
                w1 = HTT.data[i].weight;
                s1 = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (HTT.data[i].parent == 0 && i != s1)
        {
            if (w2 == -1 || HTT.data[i].weight <= w2 && HTT.data[i].weight >= w1)
            {
                w2 = HTT.data[i].weight;
                s2 = i;
            }
        }
    }
}

//根据用户输入建立huffmanTreeTable1
void CreateHuffmanTreeTable1(HuffmanTreeTable& HTT)
{
    cout << "请输入字符（回车键结束输入）：";
    int count[128] = { 0 }; //记录ASCII码中128个字符中个字符出现的次数
    int totalCount = 0;   //记录用户输入字符总数
    int charKind = 0;     //记录出现字符个数
    char str_char[10000]; //存储用户输入字符串
    cin.get(str_char, 10000);

    for (int i = 0; str_char[i] != '\0'; ++i) //遍历用户输入字符串
    {
        ++count[str_char[i]]; //统计每个字符出现次数
        ++totalCount;         //统计输入字符总数
    }

    for (int i = 0; i < 128; ++i) //遍历统计到的值
    {
        if (count[i] != 0) //如果用户输入过该字符
        {
            ++charKind; //统计字符出现个数
            cout << "字符\t" << (char)i << "\t出现次数：" << count[i] << endl;
        }
    }
    cout << "共计出现" << charKind << "种字符" << endl;
    cout << "共计出现" << totalCount << "个字符" << endl;

    HTT.charKind = charKind;     //记录字符种类
    HTT.size = 2 * charKind - 1; //记录节点个数
    // HuffmanTreeNode[0]不存数据，从索引为1处开始存结点数据
    //HTT.data = new HuffmanTreeNode[HTT.size + (unsigned __int64)1];

    //初始化HuffmanTreeTable中的各节点的元素
    for (int i = 1; i <= HTT.size; ++i)
    {
        HTT.data[i].parent = 0;
        HTT.data[i].lchild = 0;
        HTT.data[i].rchild = 0;
        HTT.data[i].huffman_code = "";
        HTT.data[i].ch = 0;
        HTT.data[i].weight = 0;
        HTT.data[i].weightPercentage = 0;
    }

    //依次输入前n个结点（叶节点：度0）的权值
    //循环charKind次，
    for (int i = 0, j = 1; i < 128; ++i) //遍历统计到的值
    {
        if (count[i] != 0) //如果用户输入过该字符
        {
            //将该字符、出现的次数、记录到huffmanTreeTalbe的第j位
            HTT.data[j].ch = (char)i;
            HTT.data[j].weight = count[i];
            HTT.data[j].weightPercentage = (double)HTT.data[j].weight / totalCount;
            ++j;
        }
    }

    //合并生成charKind - 1个结点（度2）————构造哈夫曼树
    for (int i = HTT.charKind + 1; i <= HTT.size; ++i)
    {
        int s1, s2;
        Select(HTT, i - 1, s1, s2);

        HTT.data[s1].parent = i;
        HTT.data[s2].parent = i;
        HTT.data[i].lchild = s1;
        HTT.data[i].rchild = s2;
        HTT.data[i].weight = HTT.data[s1].weight + HTT.data[s2].weight;
        HTT.data[i].weightPercentage = HTT.data[s1].weightPercentage + HTT.data[s2].weightPercentage;
    }

    char buffer[128];
    int p = 0;

    for (int i = 1; i <= HTT.charKind; ++i)
    {
        int f = HTT.data[i].parent;
        int c = i;
        while (f != 0)
        {
            if (HTT.data[f].lchild == c)
            {
                buffer[p++] = '0';
            }
            else
            {
                buffer[p++] = '1';
            }
            c = f;
            f = HTT.data[f].parent;
        }
        while (p > 0)
        {
            HTT.data[i].huffman_code += buffer[--p];
        }
    }
    cout << "成功建立哈夫曼树表" << endl;
    system("pause");
    system("cls");
}

void CreateHuffmanTreeTable2(HuffmanTreeTable& HTT)
{
    cout << "请输入需要进行哈夫曼编码字符的个数：" << endl;
    cin >> HTT.charKind;
    HTT.size = 2 * HTT.charKind - 1;

    //初始化HuffmanTreeTable中的各节点的元素
    for (int i = 1; i <= HTT.size; ++i)
    {
        HTT.data[i].parent = 0;
        HTT.data[i].lchild = 0;
        HTT.data[i].rchild = 0;
        HTT.data[i].huffman_code = "";
        HTT.data[i].ch = 0;
        HTT.data[i].weight = 0;
        HTT.data[i].weightPercentage = 0;
    }

    //依次输入前n个结点（叶节点：度0）的权值
    for (int i = 1; i <= HTT.charKind; i++)
    {
        cout << "请输入第 " << i << " 位的字符：";
        while (getchar() != '\n');
        HTT.data[i].ch = getchar();
        cout << "请输入字符 " << HTT.data[i].ch << " 的权值：";
        while (getchar() != '\n');
        cin >> HTT.data[i].weight;
    }

    //合并生成charKind - 1个结点（度2）————构造哈夫曼树
    for (int i = HTT.charKind + 1; i <= HTT.size; ++i)
    {
        int s1, s2;
        Select(HTT, i - 1, s1, s2);

        HTT.data[s1].parent = i;
        HTT.data[s2].parent = i;
        HTT.data[i].lchild = s1;
        HTT.data[i].rchild = s2;
        HTT.data[i].weight = HTT.data[s1].weight + HTT.data[s2].weight;
        //HTT.data[i].weightPercentage = HTT.data[s1].weightPercentage + HTT.data[s2].weightPercentage;
    }

    char buffer[128];
    int p = 0;

    for (int i = 1; i <= HTT.charKind; ++i)
    {
        int f = HTT.data[i].parent;
        int c = i;
        while (f != 0)
        {
            if (HTT.data[f].lchild == c)
            {
                buffer[p++] = '0';
            }
            else
            {
                buffer[p++] = '1';
            }
            c = f;
            f = HTT.data[f].parent;
        }
        while (p > 0)
        {
            HTT.data[i].huffman_code += buffer[--p];
        }
    }
    cout << "成功建立哈夫曼树表" << endl;
    system("pause");
    system("cls");
}


//根据HuffmanTreeTable对用户输入的字符进行huffman编码1
void Encode(const HuffmanTreeTable& HTT)
{
    cout << "请输入需要进行编码的字符串（回车键结束输入）：";
    char str_char[10000];
    cin.get(str_char, 10000);
    string result;

    for (int i = 0; str_char[i] != '\0'; ++i)
    {
        for (int j = 1; j <= HTT.charKind; j++)
        {
            if (str_char[i] == HTT.data[j].ch)
            {
                result += HTT.data[j].huffman_code;
                break;
            }
        }
    }
    cout << "该字符串的哈夫曼编码为：";
    cout << result << endl;
    system("pause");
    system("cls");
}

//根据HuffmanTreeTable对用户输入的huffman编码进行字符解码1
void Decode(const HuffmanTreeTable& HTT)
{
    cout << "请输入哈夫曼编码（回车键结束输入）：";
    char str_binary[10000]; //存储用户输入字符串
    cin.get(str_binary, 10000);
    string result;

    int p = HTT.size;
    for (int i = 0; str_binary[i] != '\0'; ++i)
    {
        if (str_binary[i] == '0')
        {
            p = HTT.data[p].lchild;
        }
        else if (str_binary[i] == '1')
        {
            p = HTT.data[p].rchild;
        }

        if (HTT.data[p].lchild == 0 && HTT.data[p].rchild == 0)
        {
            result += HTT.data[p].ch;
            p = HTT.size;
        }
    }

    cout << "该哈夫曼编码串的译码字符串为：";
    cout << result << endl;
    system("pause");
    system("cls");
}


//打印HuffmanTreeTable
void PrintHuffmanTreeTable(const HuffmanTreeTable& HTT)
{
    cout << "当前哈夫曼编码表中的字符为：" << endl;
    cout << "序号  " << "字符 " << "双亲结点 " << "左子节点 " << "右子节点 " << "出现次数 " << "出现频率 " << "哈夫曼编码" << endl;
    for (int i = 1; i <= HTT.charKind; ++i)
    {
        cout << i << '\t' << HTT.data[i].ch << '\t' << HTT.data[i].parent << '\t' << HTT.data[i].lchild << '\t' << HTT.data[i].rchild << '\t' << HTT.data[i].weight << '\t' << HTT.data[i].weightPercentage << '\t' << HTT.data[i].huffman_code << endl;
    }
    system("pause");
    system("cls");
}

void WriteTxt(void)
{
	ofstream ofs;

	ofs.open("", ios::out);

	//写文件


	ofs.close();
}

void ReadTxt(void)
{
	ifstream ifs;

	ifs.open("", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//读文件
	char buffer[1024] = { 0 };
	while (ifs >> buffer)
	{
		cout << buffer << endl;
	}

	ifs.close();
}

void WriteBinary(const HuffmanTreeTable& HTT)
{
	ofstream ofs;

	ofs.open("huffmanTreeTable.txt", ios::out | ios::binary);

	//写文件
	ofs.write((const char*)&HTT, sizeof(HTT));

	ofs.close();

    cout << "成功存入哈夫曼树表" << endl;
    system("pause");
    system("cls");
}

void ReadBinary(HuffmanTreeTable& HTT)
{
	ifstream ifs;

	ifs.open("huffmanTreeTable.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//读文件
	ifs.read((char*)&HTT, sizeof(HTT));

	PrintHuffmanTreeTable(HTT);

	ifs.close();

    cout << "成功读入哈夫曼树表" << endl;
    system("pause");
    system("cls");
}

void showMenu(void)
{
	cout << "*****************************************" << endl;
	cout << "***** 1、显示哈夫曼数               *****" << endl;
	cout << "***** 2、用户输入字符串建立哈夫曼树 *****" << endl;
	cout << "***** 3、用户输入权值建立哈夫曼树   *****" << endl;
	cout << "***** 4、哈夫曼编码                 *****" << endl;
	cout << "***** 5、哈夫曼解码                 *****" << endl;
	cout << "***** 6、存储哈夫曼树               *****" << endl;
	cout << "***** 7、载入哈夫曼树               *****" << endl;
	cout << "***** 0、退出系统                   *****" << endl;
	cout << "*****************************************" << endl;
	cout << "请选择：";
}

int main(void)
{
	HuffmanTreeTable HTT;
	InitTable(HTT);
	char str_char[10000] = { 0 };
	char str_binary[10000] = { 0 };

	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:		//1、显示哈夫曼数
			PrintHuffmanTreeTable(HTT);
			break;
		case 2:		//2、用户输入字符串建立哈夫曼树
			while (getchar() != '\n');
			CreateHuffmanTreeTable1(HTT);
			break;
        case 3:     //3、用户输入权值建立哈夫曼树
            while (getchar() != '\n');
            CreateHuffmanTreeTable2(HTT);
            break;
		case 4:		//4、哈夫曼编码
			while (getchar() != '\n');
			Encode(HTT);
			break;
		case 5:		//5、哈夫曼解码
			while (getchar() != '\n');
			Decode(HTT);
			break;
		case 6:		//6、存储哈夫曼树
			WriteBinary(HTT);
			break;
		case 7:		//7、载入哈夫曼树
			ReadBinary(HTT);
			break;

		case 0:		//0、退出系统
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

    return 0;
}