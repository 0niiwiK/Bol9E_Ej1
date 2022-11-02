#include <stdio.h>

void pideHoraComienzo(int *horas, int *minutos);
void pideHoraFin(int *horas, int *minutos);
int calculaDuracion();
float calculaPrecio(int duracion);
void imprimeResultados(int duracion, float precio);

int main() {
    int duracion;
    float precio;
    duracion=calculaDuracion();
    precio=calculaPrecio(duracion);
    imprimeResultados(duracion,precio);
    return 0;
}

void pideHoraComienzo(int *horas, int *minutos){
    printf("Introduce hora y minutos en que se comenzo la llamada (24h) (hh mm): ");
    scanf("%d %d",horas,minutos);
    fflush(stdin);
    while (*horas<0 || *horas>23 || *minutos<0 || *minutos>59) {
        printf("Hora o minutos erroneos\nIntroduce hora y minutos en que se comenzo la llamada (24h) (hh mm): ");
        scanf("%d %d", horas, minutos);
        fflush(stdin);
    }
}

void pideHoraFin(int *horas, int *minutos){
    printf("Introduce hora y minutos en que se termino la llamada (24h) (hh mm): ");
    scanf("%d %d",horas,minutos);
    fflush(stdin);
    while (*horas<0 || *horas>23 || *minutos<0 || *minutos>59) {
        printf("Hora o minutos erroneos\nIntroduce hora y minutos en que se termino la llamada (24h) (hh mm): ");
        scanf("%d %d", horas, minutos);
        fflush(stdin);
    }
}

int calculaDuracion(){
    int hora1,minutos1,hora2,minutos2,minutosTotales;
    pideHoraComienzo(&hora1,&minutos1);
    pideHoraFin(&hora2,&minutos2);
    while (hora2<hora1 || ((hora2==hora1)&&minutos2<minutos1)){
        printf("Hora fin no puede ser anterior a hora inicio\n");
        pideHoraFin(&hora2,&minutos2);
    }
    minutosTotales=minutos2-minutos1;
    if (minutosTotales<0){
        minutosTotales+=60;
        hora1++;
    }
    minutosTotales+=(hora2-hora1)*60;
    return minutosTotales;
}

float calculaPrecio(int duracion){
    float precio=0.12;
    if (duracion<=60)
        precio+=0.06*duracion;
    else
        precio+=3.6+(0.1*(duracion-60));
    return precio;
}

void imprimeResultados(int duracion, float precio){
    printf("\nDuracion de la llamada: %d minutos. Precio: %.2f euros",duracion,precio);
}
