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
} HuffmanTreeNode; //����huffmanTree���

typedef struct
{
    HuffmanTreeNode data[MaxSize];
    int charKind;
    int size;
} HuffmanTreeTable; //����huffmanTreeTable

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


//�����û������ַ���
void UserCinChar(char* str_char)
{
    cin.get(str_char, 10000);
}

//�����û��������������
void UserCinBinary(char* str_binary)
{
    cin.get(str_binary, 10000);
}

//��ʼ������������
void InitTable(HuffmanTreeTable& HTT)
{
    HTT.charKind = 0;
    HTT.size = 0;
}

//�ڵ�ǰ��HT[n]��1<=n<=i-1����
//ѡ������(parent == 0)��(weight��С)�Ľ�㲢�������±�s1��s2
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

//�����û����뽨��huffmanTreeTable1
void CreateHuffmanTreeTable1(HuffmanTreeTable& HTT)
{
    cout << "�������ַ����س����������룩��";
    int count[128] = { 0 }; //��¼ASCII����128���ַ��и��ַ����ֵĴ���
    int totalCount = 0;   //��¼�û������ַ�����
    int charKind = 0;     //��¼�����ַ�����
    char str_char[10000]; //�洢�û������ַ���
    cin.get(str_char, 10000);

    for (int i = 0; str_char[i] != '\0'; ++i) //�����û������ַ���
    {
        ++count[str_char[i]]; //ͳ��ÿ���ַ����ִ���
        ++totalCount;         //ͳ�������ַ�����
    }

    for (int i = 0; i < 128; ++i) //����ͳ�Ƶ���ֵ
    {
        if (count[i] != 0) //����û���������ַ�
        {
            ++charKind; //ͳ���ַ����ָ���
            cout << "�ַ�\t" << (char)i << "\t���ִ�����" << count[i] << endl;
        }
    }
    cout << "���Ƴ���" << charKind << "���ַ�" << endl;
    cout << "���Ƴ���" << totalCount << "���ַ�" << endl;

    HTT.charKind = charKind;     //��¼�ַ�����
    HTT.size = 2 * charKind - 1; //��¼�ڵ����
    // HuffmanTreeNode[0]�������ݣ�������Ϊ1����ʼ��������
    //HTT.data = new HuffmanTreeNode[HTT.size + (unsigned __int64)1];

    //��ʼ��HuffmanTreeTable�еĸ��ڵ��Ԫ��
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

    //��������ǰn����㣨Ҷ�ڵ㣺��0����Ȩֵ
    //ѭ��charKind�Σ�
    for (int i = 0, j = 1; i < 128; ++i) //����ͳ�Ƶ���ֵ
    {
        if (count[i] != 0) //����û���������ַ�
        {
            //�����ַ������ֵĴ�������¼��huffmanTreeTalbe�ĵ�jλ
            HTT.data[j].ch = (char)i;
            HTT.data[j].weight = count[i];
            HTT.data[j].weightPercentage = (double)HTT.data[j].weight / totalCount;
            ++j;
        }
    }

    //�ϲ�����charKind - 1����㣨��2���������������������
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
    cout << "�ɹ���������������" << endl;
    system("pause");
    system("cls");
}

void CreateHuffmanTreeTable2(HuffmanTreeTable& HTT)
{
    cout << "��������Ҫ���й����������ַ��ĸ�����" << endl;
    cin >> HTT.charKind;
    HTT.size = 2 * HTT.charKind - 1;

    //��ʼ��HuffmanTreeTable�еĸ��ڵ��Ԫ��
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

    //��������ǰn����㣨Ҷ�ڵ㣺��0����Ȩֵ
    for (int i = 1; i <= HTT.charKind; i++)
    {
        cout << "������� " << i << " λ���ַ���";
        while (getchar() != '\n');
        HTT.data[i].ch = getchar();
        cout << "�������ַ� " << HTT.data[i].ch << " ��Ȩֵ��";
        while (getchar() != '\n');
        cin >> HTT.data[i].weight;
    }

    //�ϲ�����charKind - 1����㣨��2���������������������
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
    cout << "�ɹ���������������" << endl;
    system("pause");
    system("cls");
}


//����HuffmanTreeTable���û�������ַ�����huffman����1
void Encode(const HuffmanTreeTable& HTT)
{
    cout << "��������Ҫ���б�����ַ������س����������룩��";
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
    cout << "���ַ����Ĺ���������Ϊ��";
    cout << result << endl;
    system("pause");
    system("cls");
}

//����HuffmanTreeTable���û������huffman��������ַ�����1
void Decode(const HuffmanTreeTable& HTT)
{
    cout << "��������������루�س����������룩��";
    char str_binary[10000]; //�洢�û������ַ���
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

    cout << "�ù��������봮�������ַ���Ϊ��";
    cout << result << endl;
    system("pause");
    system("cls");
}


//��ӡHuffmanTreeTable
void PrintHuffmanTreeTable(const HuffmanTreeTable& HTT)
{
    cout << "��ǰ������������е��ַ�Ϊ��" << endl;
    cout << "���  " << "�ַ� " << "˫�׽�� " << "���ӽڵ� " << "���ӽڵ� " << "���ִ��� " << "����Ƶ�� " << "����������" << endl;
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

	//д�ļ�


	ofs.close();
}

void ReadTxt(void)
{
	ifstream ifs;

	ifs.open("", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//���ļ�
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

	//д�ļ�
	ofs.write((const char*)&HTT, sizeof(HTT));

	ofs.close();

    cout << "�ɹ��������������" << endl;
    system("pause");
    system("cls");
}

void ReadBinary(HuffmanTreeTable& HTT)
{
	ifstream ifs;

	ifs.open("huffmanTreeTable.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//���ļ�
	ifs.read((char*)&HTT, sizeof(HTT));

	PrintHuffmanTreeTable(HTT);

	ifs.close();

    cout << "�ɹ��������������" << endl;
    system("pause");
    system("cls");
}

void showMenu(void)
{
	cout << "*****************************************" << endl;
	cout << "***** 1����ʾ��������               *****" << endl;
	cout << "***** 2���û������ַ��������������� *****" << endl;
	cout << "***** 3���û�����Ȩֵ������������   *****" << endl;
	cout << "***** 4������������                 *****" << endl;
	cout << "***** 5������������                 *****" << endl;
	cout << "***** 6���洢��������               *****" << endl;
	cout << "***** 7�������������               *****" << endl;
	cout << "***** 0���˳�ϵͳ                   *****" << endl;
	cout << "*****************************************" << endl;
	cout << "��ѡ��";
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
		case 1:		//1����ʾ��������
			PrintHuffmanTreeTable(HTT);
			break;
		case 2:		//2���û������ַ���������������
			while (getchar() != '\n');
			CreateHuffmanTreeTable1(HTT);
			break;
        case 3:     //3���û�����Ȩֵ������������
            while (getchar() != '\n');
            CreateHuffmanTreeTable2(HTT);
            break;
		case 4:		//4������������
			while (getchar() != '\n');
			Encode(HTT);
			break;
		case 5:		//5������������
			while (getchar() != '\n');
			Decode(HTT);
			break;
		case 6:		//6���洢��������
			WriteBinary(HTT);
			break;
		case 7:		//7�������������
			ReadBinary(HTT);
			break;

		case 0:		//0���˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

    return 0;
}