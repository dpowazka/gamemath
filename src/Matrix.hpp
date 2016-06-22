#pragma once
#include <stdexcept>

template <typename T>
class Matrix {
	template <typename S> friend void print(const Matrix<S> &matrix);
public:
	int const cols;
	int const rows;
private:
	T** matrix;
public:
	Matrix(int p_rows, int p_cols) :
		rows(p_rows),
		cols(p_cols)
	{
		matrix = new T*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	Matrix(const Matrix& other) :
		cols(other.cols),
		rows(other.rows)
	{
		matrix = new T*[rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = other(i, j);
			}
		}
	}

	void operator=(const Matrix& other) {
		if (&other == this) return;

		if (cols != other.cols || rows != other.rows)   {
			throw std::runtime_error("operator= different matrix size");
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = other(i, j);
			}
		}
	}

	//Since you can't have operator[](int row, int col) and using proxy objects
	//would be to heavy at this point. We hack this for now:
	T& operator()(int row, int col) {
		if (row >= rows || col >= cols) {
			throw std::runtime_error("Wrong row or col.");
		}
		return matrix[row][col];
	}

	const T& operator()(int row, int col) const {
		if (row >= rows || col >= cols) {
			throw std::runtime_error("Wrong row or col.");
		}
		return matrix[row][col];
	}

	
	const Matrix<T> operator+(const Matrix<T>& other) const {
		if (cols != other.cols || rows != other.rows)   {
			throw std::runtime_error("different matrix size");
		}
		Matrix<T> result((*this));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result(i, j) += other(i, j);
			}
		}
		return result;
	}

	void operator+=(const Matrix<T>& other) {
		if (cols != other.cols || rows != other.rows)   {
			throw std::runtime_error("different matrix size");
		}
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				matrix[row][col] += other(row, col);
			}
		}
	}

	const Matrix<T> operator-(const Matrix<T>& other) const {
		if (cols != other.cols || rows != other.rows)   {
			throw std::runtime_error("different matrix size");
		}

		Matrix<T> result(this);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result(i, j) -= other(i, j);
			}
		}
		return result;
	}

	const Matrix<T> operator*(const Matrix<T>& other) const {
		Matrix<T> result(rows, other.cols);
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < other.cols; col++) {
				for (int i = 0; i < cols; i++) {
					result(row, col) += matrix[row][i] * other(i, col);
				}
			}
		}
		return result;
	}

	void operator*=(const Matrix<T>& other) {
		Matrix<T> result = (*this) * other;
		(*this) = result; 
	}

	const Matrix<T> operator*(const T& number) const {
		Matrix<T> result(*this);
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				result(row, col) *= number;
			}
		}
		return result;
	}

	void operator*=(const T& number) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				matrix[row][col] *= number;
			}
		}
	}

	void singularize() {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (row == col) {
					matrix[row][col] = 1;
				}else {
					matrix[row][col] = 0;
				}
			}
		}
	}


	virtual ~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete matrix[i];
		}
		delete[] matrix;
	}
};

template <typename T, typename K>
Matrix<K> operator*(const T& number, const Matrix<K> &matrix) {
	return matrix*number;
}

template <typename T>
void print(const Matrix<T> &matrix) {
	for (int row = 0; row < matrix.rows; row++) {
		for (int col = 0; col < matrix.cols; col++) {
			printf("%f", matrix.matrix[row][col]);
			printf(" ");
		}
		printf("\n");
	}
}
