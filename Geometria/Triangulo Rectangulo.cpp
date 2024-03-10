// verificar Triangulo Rectangulo
struct Punto{
	int x,y;
};
double m(Punto p1,Punto p2){
	return ( p2.y - p1.y) / (p2.x - p1.x);
}
bool esTrianguloRectangulo(Punto p1, Punto p2, Punto p3) {
    double pendiente1 = m(p1, p2);
    double pendiente2 = m(p2, p3);
    double pendiente3 = m(p3, p1);
    // Verifica si dos pendientes son negativas recíprocas (perpendiculares)
    return fabs(pendiente1 * pendiente2 + 1) < 0.0001 ||
           fabs(pendiente2 * pendiente3 + 1) < 0.0001 ||
           fabs(pendiente3 * pendiente1 + 1) < 0.0001;
}