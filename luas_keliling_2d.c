#include<stdio.h>
#include<math.h>

//buat tipe data abstrak string dari tipe data char
typedef char* String;

//deklarasi variabel
int i, pil;
float PHI = 3.14;
float r,luas,keliling;
float a,b,c;
float d1,d2,s;
float a,t,b;
float sisi_kanan, sisi_kiri;
char pilihan;

//deklarasi prosedur
void garis(int n);
void judul();
void menu();
void luas_segitiga_sembarang();
void keliling_segitiga_sembarang();
void luas_belah_ketupat();
void keliling_belah_ketupat();
void luas_jajar_genjang();
void keliling_jajar_genjang();
void luas_trapesium();
void keliling_trapesium();
void luas_lingkaran();
void keliling_lingkaran();
float isAngka(String keterangan);
float isValid(String keterangan);

//fungsi main
int main(){
    judul(); //panggil judul
    menu(); //panggil menu
}

//prosedur menampilkan garis
void garis(int n){
    for(i=0;i<=n;i++){
        printf("=");
    }
}

void luas_segitiga_sembarang(){
    s = (a+b+c)/2;
    luas = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("\nLuas = akar(%.2f * (%.2f - %.2f) * (%.2f - %.2f) * (%.2f - %.2f))\n",s,s,a,s,b,s,c);
	  printf("     = %.2f\n\n",luas);
}

void keliling_segitiga_sembarang(){
    keliling = (a+b+c);
    printf("Kll  = %.2f + %.2f + %.2f\n",a,b,c);
	  printf("     = %.2f\n\n",keliling);
}

void luas_belah_ketupat(){
	luas = d1 * d2 * 0.5;
	printf("\nLuas = %.2f * %.2f * 0.5\n",d1,d2);
	printf("     = %.2f\n\n",luas);
}

void keliling_belah_ketupat(){
	keliling = s * 4;
	printf("Kll  = %.2f * 4\n",s);
	printf("     = %.2f\n",keliling);
}

void luas_jajar_genjang(){
	luas = a * t;
	printf("\nLuas = %.2f * %.2f\n",a,t);
	printf("     = %.2f\n\n",luas);
}

void keliling_jajar_genjang(){
	keliling = 2 * (a+b);
	printf("Kll  = 2 * ( %.2f + %.2f )\n",a,b);
	printf("     = %.2f\n",keliling);
}

void luas_trapesium(){
	luas = (a+b)*t*0.5;
	printf("\nLuas = ( %.2f * %.2f ) * %.2f * 0.5\n",a,b,t);
	printf("     = %.2f\n\n",luas);
}

void keliling_trapesium(){
	keliling = a + b + sisi_kanan + sisi_kiri;
	printf("Kll  = %.2f + %.2f + %.2f + %.2f\n",a,b,sisi_kanan,sisi_kiri);
	printf("     = %.2f\n",keliling);
}
void luas_lingkaran(){
	luas = PHI*r*r;
	printf("\nLuas = %.2f * %.2f * %.2f\n",PHI,r,r);
	printf("     = %.2f\n\n",luas);
}

void keliling_lingkaran(){
	keliling = 2*PHI*r;
	printf("Kll  = 2 * %.2f * %.2f\n",PHI,r);
	printf("     = %.2f",keliling);
}

//fungsi validasi angka
float isAngka(String keterangan){
    float x;
    printf("Masukkan %s : ", keterangan);
    if(scanf("%f", &x) == 0){
        printf("Inputan harus angka, coba lagi!\n\n");
        fflush(stdin); //bersihkan output buffer
        return;
    }
    fflush(stdin);
    return x;
}

//fungsi validasi angka
float isValid(String keterangan){
    float x;
    printf("Masukkan %s : ", keterangan);
    if(scanf("%f", &x) == 0){
        fflush(stdin); //bersihkan output buffer
        return;
    }
    fflush(stdin);
    return x;
}

//prosedur print judul
void judul(){
    garis(32); //panggil prosedur garis
    printf("\nHITUNG LUAS DAN KELILING\n");
    garis(32); //panggil prosedur garis
}

//menu
void menu(){
	printf("\nPilih Menu : ");
	printf("\n[1] Segitga Sembarang");
	printf("\n[2] Belah Ketupat");
	printf("\n[3] Jajargenjang");
	printf("\n[4] Trapesium");
	printf("\n[5] Lingkaran\n\n");

	pil = isValid("Pilihan (1-5)");
    if(isnan(pil))menu();

	switch (pil){
		case 1 :
		    printf("\n[SEGITIGA SEMBARANG]\n");

		    a:
		    a = isAngka("sisi a");
        if(isnan(a))goto a;

        b:
		    b = isAngka("sisi b");
        if(isnan(b))goto b;

        c:
		    c = isAngka("sisi c");
        if(isnan(c))goto c;

        luas_segitiga_sembarang();
        keliling_segitiga_sembarang();
        break;

        case 2 :
            printf("\n[BELAH KETUPAT]\n");

            d1:
		        d1 = isAngka("diagonal 1  ");
            if(isnan(d1))goto d1;

            d2:
		        d2 = isAngka("diagonal 2  ");
            if(isnan(d2))goto d2;

            s:
		        s = isAngka("panjang sisi");
            if(isnan(s))goto s;

            luas_belah_ketupat();
            keliling_belah_ketupat();
            break;

        case 3 :
            printf("\n[JAJAR GENJANG]\n");

            a_jajar:
		        a = isAngka("alas  ");
            if(isnan(a))goto a_jajar;

            t_jajar:
		        t = isAngka("tinggi");
            if(isnan(t))goto t_jajar;

            luas_jajar_genjang();
            keliling_jajar_genjang();
            break;

        case 4 :
            printf("\n[TRAPESIUM]\n");

            a_tpsm:
		        a = isAngka("sisi atas ");
            if(isnan(a))goto a_tpsm;

            b_tpsm:
		        b = isAngka("sisi bawah");
            if(isnan(b))goto b_tpsm;

            r_tpsm:
		        sisi_kanan = isAngka("sisi kanan");
            if(isnan(sisi_kanan))goto r_tpsm;

            l_tpsm:
		        sisi_kiri = isAngka("sisi kiri ");
            if(isnan(sisi_kiri))goto l_tpsm;

            t_tpsm:
		        t = isAngka("tinggi    ");
            if(isnan(t))goto t_tpsm;

            luas_trapesium();
            keliling_trapesium();
            break;

        case 5 :
            printf("\n[LINGKARAN]\n");

            jari:
		        r = isAngka("jari jari");
            if(isnan(r))goto jari;

            luas_lingkaran();
            keliling_lingkaran();
            break;

        default :
            printf("Inputan harus angka antara 1-5, coba lagi!\n");
            menu();
            break;
	}

    printf("\nIngin melakukan lagi? (y/t) : ");
    scanf("%s", &pilihan);

    if ((pilihan == 'y') || (pilihan == 'Y')){ //jika pilihan y, maka lakukan lagi
        menu(); //rekursif
    }
}
