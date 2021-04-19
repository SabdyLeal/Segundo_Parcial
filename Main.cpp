#include <mysql.h>
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

int q_estado;
MYSQL* conectar;
void menu();
void crud_Puestos();
void crear_Puestos();
void leer_Puestos();
void actualizar_Puestos();
void eliminar_Puestos();
void crud_Empleados();
void crear_Empleados();
void leer_Empleados();
void actualizar_Empleados();
void eliminar_Empleados();

int main()
{
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_impar", 3306, NULL, 0);
    if (conectar) {
        
        menu();
    }
    else {
        cout << "Error en la conexión..." << endl;
    }
    system("pause");
    return 0;
}

void menu() {
    int opcion;

    while (true) {

        cout << "              Menú" << endl;
        cout << "                     1.Marcas" << endl;
        cout << "                     2.Productos" << endl;
        cout << "                      3.Salir\n" << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crud_Puestos();
                break;
            case 2:
                crud_Empleados();
                break;
            case 3:
                exit(1);
            default:
                cout << "\nLa opción ingresada es incorrecta\n" << endl;
                break;
        }

        cout << "---------------------------------------\n" << endl;

    }
}

void crud_Puestos() {
    int opcion;
    bool bandera = true;

    while (bandera) {

        cout << "\nMarcas" << endl;
        cout << "    1.Crear" << endl;
        cout << "    2.Leer" << endl;
        cout << "    3.Actualizar" << endl;
        cout << "    4.Eliminar" << endl;
        cout << "    5.Regresar\n" << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cin.ignore();
                crear_Puesto();
                break;
            case 2:
                leer_Puestos();
                break;
            case 3:
                actualizar_Puesto();
                break;
            case 4:
                eliminar_Puesto();
                break;
            case 5:
                bandera = false;
                break;
            default:
                cout << "\nLa opción ingresada es incorrecta\n" << endl;
                break;
        }

        cout << "\n---------------------------------------" << endl;

    }
}

void crear_Puesto() {
    string Puesto, consulta;
    cout << "\nNombre de al puesto: ";
    getline(cin, Puesto);
    consulta = "INSERT INTO marcas(puesto) VALUES('" + Puesto + "');";
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Marca ingresada con éxito" << endl;
        leer_Puestos();
    }
    else {
        cout << "Error al ingresar el puesto" << endl;
    }
}

void leer_Puestos() {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    string consulta;
    consulta = "SELECT * FROM db:impar.Puestos;";
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "\n--------------------------" << endl;
        cout << "id\t| Puesto" << endl;
        cout << "--------------------------" << endl;
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "\t| " << fila[1] << endl;
            cout << "--------------------------" << endl;
        }
    }
    else {
        cout << "Error al leer Puestos" << endl;
    }
}

void actualizar_Puesto() {
    int idempleado, idpuesto;
    string Puesto, consulta;

    leer_Puestos();

    cout << "\nId de la Puesto: "; 
    cin >> id;

    cin.ignore();

    cout << "\nNombre de la Puesto: ";
    getline(cin, Puesto);

    consulta = "UPDATE marcas SET Puesto = '" + marca + "' WHERE id = " + to_string(id);
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Marca actualizada con éxito" << endl;
        leer_Puestos();
    }
    else {
        cout << "Error al actualizar Puesto" << endl;
    }
}

void eliminar_Puesto() {
    int id;
    string Puesto, consulta;

    leer_Puesto();

    cout << "\nId de la Puesto: ";
    cin >> id;

    consulta = "DELETE FROM marcas WHERE Puesto.id = " + to_string(id);
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Marca eliminada con éxito" << endl;
        leer_Puesto();
    }
    else {
        cout << "Error al eliminar Puesto" << endl;
    }
}

void crud_Empleados() {
    int opcion;
    bool bandera = true;

    while (bandera) {

        cout << "\nProductos" << endl;
        cout << "    1.Crear" << endl;
        cout << "    2.Leer" << endl;
        cout << "    3.Actualizar" << endl;
        cout << "    4.Eliminar" << endl;
        cout << "    5.Regresar\n" << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cin.ignore();
            crear_Empleados();
            break;
        case 2:
            leer_Empleados();
            break;
        case 3:
            actualizar_Empleado();
            break;
        case 4:
            eliminar_Empleado();
            break;
        case 5:
            bandera = false;
            break;
        default:
            cout << "\nLa opción ingresada es incorrecta\n" << endl;
            break;
        }

        cout << "\n---------------------------------------" << endl;

    }
}

void crear_Empleado() {
    int  id empleado, id_puesto;
    double idempleado ,nombre,apellido , telefono,DPI,genero,fecha_nacimiento,idpuesto,fecha_inicio_labores,fecha_ingreso;
    cout << "\nNombre de Empleado: ";
    getline(cin, nombre);

    cout << "\nApellido: ";
    getline(cin, apellido);

    cout << "\ntelefono : ";
    cin >> telefono;

    cout << "\nDPI: ";
    cin >> DPI;

    cout << "\ngenero: ";
    cin >> genero;

    leer_marcas();
    cout << "\nId de puesto: ";
    cin >> id_puesto;

    consulta = "INSERT INTO Empleados(idempleado ,nombre,apellido , telefono,DPI,genero,fecha_nacimiento,idpuesto,fecha_inicio_labores,fecha_ingreso) VALUES('" + producto + "', '" + descripcion + "', '" + to_string(precio_costo) + "', '" + to_string(precio_venta) + "', '" + to_string(existencia) + "', CURRENT_TIMESTAMP(), '" + to_string(id_marca) +"');";
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Producto ingresado con éxito" << endl;
        leer_productos();
    }
    else {
        cout << "Error al ingresar Empleados" << endl;
    }
}

void leer_Empleados() {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    string consulta;
    consulta = "SELECT * FROM Empleados LEFT JOIN marcas ON Empleados.id_marca = Puestos.id;";
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        cout << "\n-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "id\t| empleado\t| nombre\t| apellido\t| relefono\t| DPI\t| genero \t|fecha_nacimiento\t|idPuesto \t|fecha_inicio \t|fecha_ingreso" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "\t| " << fila[1] << "\t| " << fila[2] << "\t| " << fila[4] << "\t| " << fila[5] << "\t| " << fila[6] << "\t| " << fila[7] << "\t| " << fila[10] <<endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    else {
        cout << "Error al leer Empleados" << endl;
    }
}

void actualizar_Empleados() {
    int id_idempleado, id_puesto;
    double idempleado , nombre ,apellido ,telefono ,DPI ,genero ,fecha_nacimiento ,idpuesto ,fecha_inicio_labores,fecha_ingreso ;

    leer_Empleados();

  cout << "\nNombre de Empleado: ";
    getline(cin, nombre);

    cout << "\nApellido: ";
    getline(cin, apellido);

    cout << "\ntelefono : ";
    cin >> telefono;

    cout << "\nDPI: ";
    cin >> DPI;

    cout << "\ngenero: ";
    cin >> genero;

    leer_marcas();
    cout << "\nId de puesto: ";
    cin >> id_puesto;

    consulta = "UPDATE productos SET Empleados = '" + Empleado + "', nombres = '" + nombre +"', DPI = '" + to_string(DPI) + "', precio_venta = '" + to_string(precio_venta) + "', telefono = '" + to_string(telefono) + "', fecha_ingreso = CURRENT_TIMESTAMP(), id_puestos = " + to_string(id_puestos) + " WHERE id = " + to_string(id_empleados);
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Empleado actualizado con éxito" << endl;
        leer_productos();
    }
    else {
        cout << "Error al actualizar Empleado" << endl;
    }
}

void eliminar_Empleados() {
    int id;
    string Empleados, consulta;

    leer_productos();

    cout << "\nId del Empleados: ";
    cin >> id;

    consulta = "DELETE FROM productos WHERE Empleados.id = " + to_string(id);
    const char* i = consulta.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Empleado eliminado " << endl;
        leer_Empleados();
    }
    else {
        cout << "Error al eliminar el empleado" << endl;
    }
}
