#include"shaderClass.h"

// Reads a text file and outputs a string with everything in the text file
string get_file_contents(const char* filename)
{
	ifstream in(filename, ios::binary);
	if (in){
		string contents;
		in.seekg(0, ios::end);
		contents.resize(in.tellg());
		in.seekg(0, ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile){
	// Read vertexFile and fragmentFile and store the strings
	try {
		// Read vertexFile and fragmentFile and store the strings
		string vertexCode = get_file_contents(vertexFile);
		string fragmentCode = get_file_contents(fragmentFile);

		// Convert the shader source strings into character arrays
		const char* vertexSource = vertexCode.c_str();
		const char* fragmentSource = fragmentCode.c_str();

		// Create Vertex Shader Object and get its reference
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		// Attach Vertex Shader source to the Vertex Shader Object
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(vertexShader);

		// Create Fragment Shader Object and get its reference
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Attach Fragment Shader source to the Fragment Shader Object
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(fragmentShader);

		// Create Shader Program Object and get its reference
		ID = glCreateProgram();
		// Attach the Vertex and Fragment Shaders to the Shader Program
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		// Wrap-up/Link all the shaders together into the Shader Program
		glLinkProgram(ID);

		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	catch (int e) {
		char error_message[256];
		strerror_s(error_message, sizeof(error_message), e);
		cerr << "Error al abrir el archivo: " << error_message << endl;
		// Maneja el error como consideres apropiado
	}
}

// Activates the Shader Program
void Shader::Activate(){
	glUseProgram(ID);
}

// Deletes the Shader Program
void Shader::Delete(){
	glDeleteProgram(ID);
}