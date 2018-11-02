
#include "stdafx.h"

#include "stdafx.h"


#include "Header.h"




Matrix::Matrix() {}//конструктор по умолчанию ( может быть вызван без передачи аргументов)-
				   //-в C ++ конструкторы по умолчанию имеют существенное значение, поскольку они автоматически вызываются 
				   //при определенных обстоятельствах (когда объект объявляется без аргументов или создаётся новый экземпляр в памяти
				   // (напр. new MyClass) или когда конструктор класса не вызывает явно конструктор хотя бы одного из своих полей-объектов 
				   //в списке инициализации;

Matrix::Matrix(int row, int cols) : rows(row), columns(cols) {

	arr = new int*[row];//динамическое выделение памяти необходимо для эффективного использования памяти компьютера (в
						//отличии от статич. выделения памяти), операции new и delete предназначены для динамического распределения памяти компьютера,
						//операция new создает объект заданного типа, выделяет ему память из свободной области памяти и возвращает указатель правильного типа на данный участок памяти.
						//(если память невозможно выделить (в случае отсутствия свободных участков), то возвращается нулевой указатель;delete высвобождает выделенную память;

	for (int i = 0; i < row; i++) {

		arr[i] = new int[cols] {};

	}//в цикле каждой строке массива объявленного выше выделяется память под cols элементов - 
	 //в результате получается двумерный динамический массив  arr[row][cols] (т.е. arr - массив указателей 
	 //на выделенный участок памяти под массив чисел int;

}//список инициализации членов класса напрямую (т.е. прямая инициализация), где в {} -
 //-инициализация через присваивание или копирующая инициализация;



Matrix::~Matrix() {

		        for(int i = 0; i < rows; i++){

	            delete[] arr[i];

		        }

	            delete[] arr;

}//деструктор для деинициализации объекта (освобождения памяти), ПОЧЕМУ-ТО РАБОТАЕТ ТОЛЬКО ДЕСТРУКТОР ПО УМОЛЧАНИЮ
 //(НЕОБРАБОТАННОЕ ИСКЛЮЧЕНИЕ ПРИ ИСПОЛЬЗОВАНИИ ДИНАМИЧЕСКОГО ОСВОБОЖДЕНИЯ ПАМЯТИ В ТЕЛЕ ДЕСТРУКТОРА;



int Matrix::Rows() {

	return rows;

}



int Matrix::Columns() {

	return columns;

}
//GET-методы для полей класса rows и columns;

int Matrix::Element(int i, int j) {

	if (i < rows && j < columns) {

		return arr[i][j];

	}
	else {

		return 1;

	}

}//поиск элемента в матрице;


void Matrix::Read(string filename) {

	ifstream file(filename);//создаем объект класса ifstream и открываем файл в конструкторе данного класса
							//(по-другому можно через метод класса open());



	if (!file.is_open()) {//вызов метода is_open - вернет 1, если файл найден и успешно открыт, иначе вернет 0;

		cout << "ERROR";

	}
	else {

		file >> rows >> columns;//считывание числа строк и столбцов в поля класса Matrix (первая строка в файле) - 
								//- считывание строки закончится, если появится пробел или конец строки;





		for (int i = 0; i < rows; i++) {

			arr[i] = new int[columns];

		}



		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < columns; j++) {

				file >> arr[i][j];//считываем в массив сами элементы матрицы;

			}

		}

	}

	

}//метод заполнения матрицы из файла;



void Matrix::Print() {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			cout << arr[i][j] << " ";

		}

		cout << endl;

	}

}//вывод в консоль матрицы;


 //Перегрузка операторов — один из способов реализации полиморфизма, заключающийся в возможности одновременного 
 //существования в одной области видимости нескольких различных вариантов применения оператора, имеющих одно и то же имя, 
 //но различающихся типами параметров, к которым они применяются (чтобы разрешить существование нескольких одноимённых операций, 
 //достаточно ввести в язык правило, согласно которому оператор опознается компилятором не только 
 //по обозначению, но и по типам его параметров).
Matrix Matrix::operator+(Matrix& other)const {//передача параметра в функцию осуществляется по левосторонней ссылке (ссылка -псевдоним другого объекта или значения) - копируется только 
											  //указатель на объект (чем ссылка и является на самом низком уровне) (в случае передачи по значению (т. е. Matrix other - компилятор создаёт полноценную копию объекта путём выделения памяти на стеке и 
											  //вызова конструктора копирования (определение - специальный конструктор, применяемый для создания нового объекта как копии уже существующего 
											  // (его работа заключается в том, чтобы создать реальную копию объекта со своей личной выделенной динамической памятью, синтаксис: 
											  // имяКласса (const имяКласса & object) {});
											  //const при объявлении функции - указывает, что функция доступна только для чтения и не изменяет объект, для которого вызывается;

	assert(rows == other.rows && columns == other.columns);//Функция assert оценивает выражение, которое передается ей в качестве аргумента, 
														   //через параметр expression. Если аргумент-выражение этого макроса в функциональной форме равно нулю (т.е. выражение ложно), 
														   //сообщение записывается на стандартное устройство вывода ошибок и вызывается функция abort, работа программы прекращается.

	Matrix result(other.rows, other.columns);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			result.arr[i][j] = arr[i][j] + other.arr[i][j];

		}

	}

	return result;

}



Matrix Matrix::operator-(Matrix& other)const {

	assert(rows == other.rows && columns == other.columns);

	Matrix result(other.rows, other.columns);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			result.arr[i][j] = arr[i][j] - other.arr[i][j];

		}

	}

	return result;

}



Matrix Matrix::operator*(Matrix& other)const {

	assert(columns == other.rows);

	Matrix result(rows, other.columns);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < other.columns; j++) {

			int tmp = 0;

			for (int t = 0; t < columns; t++) {

				tmp += arr[i][t] * other.arr[t][j];

			}

			result.arr[i][j] = tmp;

		}

	}

	return result;

}// умножение матриц l*m и m*n - матрица l*n, где элемент Cij = sum(Air*Brj);



Matrix Matrix::Transp()const {

	Matrix result(columns, rows);

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			result.arr[j][i] = arr[i][j];

		}

	}

	return result;

}//транспонирование - строки матрицы становятся столбцами;



Matrix Matrix::operator=(Matrix& other)const {//оператор присваивания;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			arr[i][j] = other.arr[i][j];

		}

	}

	return *this;//при создании объекта класса и вызове методов (напр. в main), которые принадлежат классу, им неявно передается указатель this -
				 //- указывает на адрес созданного объекта класса (т.е. тип указателя - имя класса) - является скрытым первым параметром любого метода класса 
				 //(кроме статических методов); *this - возвращает текущий объект из функции;

}



bool Matrix::operator==(Matrix& other)const {//оператор сравнения;

	if (rows != other.rows || columns != other.columns) {

		return false;

	}
	else {

		for (int i = 0; i < rows; i++) {

			for (int j = 0; j < columns; j++) {

				if (other.arr[i][j] != arr[i][j]) {

					return false;

				}

			}

		}

	}

	return true;

}



istream& operator >> (istream& is, Matrix& other) {//оператор ввода - на вход подается ссылка на поток ввода -
												   //-объект класса istream);

	for (int i = 0; i < other.rows; i++) {

		for (int j = 0; j < other.columns; j++) {

			cout << "arr[" << i << "][" << j << "] = ";

			is >> other.arr[i][j];

		}

	}

	return is;

}



ostream& operator<<(ostream& os, const Matrix& other) {//оператор вывода;

	for (int i = 0; i < other.rows; i++) {

		for (int j = 0; j < other.columns; j++) {

			os.width(other.rows);//функция width класса ostream для выравниваются по правому краю столбца 
								 //шириной по крайней мере {other.rows} символов;

			os << other.arr[i][j] << " ";

		}

		os << "\n";

	}

	return os;

}




int main()
{
	setlocale(LC_ALL, "Russian");

	string A = "C:/Users/User/Documents/A.txt";

	string B = "C:/Users/User/Documents/B.txt";

	string C = "C:/Users/User/Documents/C.txt";

	string D = "C:/Users/User/Documents/D.txt";

	string E = "C:/Users/User/Documents/E.txt";

	string F = "C:/Users/User/Documents/F.txt";

	Matrix matrix1;

	Matrix matrix2;

	Matrix matrix3;

	Matrix matrix4;

	Matrix matrix5;

	Matrix matrix6;

	Matrix matrix7(3, 3);

	cin >> matrix7;

	cout << "\nВведенная матрица:" << endl;

	cout << matrix7;


	cout << "\nMatrix A:" << endl;

	matrix1.Read(A);

	cout << matrix1;



	cout << "\nMatrix B:" << endl;

	matrix2.Read(B);

	cout << matrix2;



	cout << "\nMatrix C:" << endl;

	matrix3.Read(C);

	cout << matrix3;


	cout << "\nMatrix D:" << endl;

	matrix4.Read(D);

	cout << matrix4;


	cout << "\nMatrix E:" << endl;

	matrix5.Read(E);

	cout << matrix5;


	cout << "\nMatrix F:" << endl;

	matrix6.Read(F);

	cout << matrix6;



	cout << "\nMatrix A + Matrix B:" << endl;


	cout << "Сумма матриц A и B == C? => " << ((matrix1 + matrix2) == matrix3);





	cout << "\nMatrix A - Matrix B:" << endl;

	cout << "Разность матриц A и B == D? => " << ((matrix1 - matrix2) == matrix4);



	cout << "\nMatrix A * Matrix B:" << endl;

	cout << "Произведение матриц A и B == E? => " << ((matrix1 * matrix2) == matrix5);


	cout << "\nMatrix F -> Транспонированная матрица:" << endl;

	matrix6.Transp().Print();

	system("PAUSE");



	return 0;
}
