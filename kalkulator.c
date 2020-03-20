#include<stdio.h>
#include<math.h>

//buat tipe data abstrak string dari tipe data char
typedef char* String;

//deklarasi variabel
int i, pil, mod1, mod2;
float bil1, bil2;;
char pilihan;

//deklarasi prosedur dan fungsi
float bilangan1();
float bilangan2();
void garis(int n);
void judul();
void menu();
float isAngka(String keterangan);
float isValid(String keterangan);

//fungsi main
int main(){
    judul(); //panggil judul
    menu();
}

//prosedur menampilkan garis
void garis(int n){
    for(i=0;i<=n;i++){
        printf("=");
    }
}

//prosedur print judul
void judul(){
    garis(20); //panggil prosedur garis
    printf("\nKALKULATOR SEDERHANA\n");
    garis(20); //panggil prosedur garis
}

//fungsi validasi angka
float isAngka(String keterangan){
    float x;
    printf("Masukkan %s : ", keterangan);
    if(scanf("%f", &x) == 0){
        printf("Inputan harus angka, coba lagi!\n");
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

//menu
void menu(){
	printf("\nPilih Menu : ");
	printf("\n[1] Perkalian");
	printf("\n[2] Pembagian");
	printf("\n[3] Penjumlahan");
	printf("\n[4] Pengurangan");
	printf("\n[5] Modulus\n");

    pil = isValid("Pilihan (1-5)");
    if(isnan(pil))menu();

    switch (pil){
	case 1 :
		printf("\n[PERKALIAN]\n");

		bil1_kali:
            	bil1 = isAngka("bilangan 1");
            	if(isnan(bil1))goto bil1_kali;

		bil2_kali:
           	bil2 = isAngka("bilangan 2");
           	if(isnan(bil2))goto bil2_kali;

		printf("Hasil %.2f x %.2f = %.2f\n", bil1, bil2, bil1*bil2);

            	break;

	case 2 :
		printf("\n[PEMBAGIAN]\n");

		bil1_bagi:
		bil1 = isAngka("bilangan 1");
		if(isnan(bil1))goto bil1_bagi;

		bil2_bagi:
            	bil2 = isAngka("bilangan 2");
            	if(isnan(bil2))goto bil2_bagi;

		printf("Hasil %.2f : %.2f = %.2f\n", bil1, bil2, bil1/bil2);
            	break;

	case 3 :
		printf("\n[PENJUMLAHAN]\n");

		bil1_jumlah:
            	bil1 = isAngka("bilangan 1");
            	if(isnan(bil1))goto bil1_jumlah;

		bil2_jumlah:
            	bil2 = isAngka("bilangan 2");
            	if(isnan(bil2))goto bil2_jumlah;

		printf("Hasil %.2f + %.2f = %.2f\n", bil1, bil2, bil1+bil2);
            break;

		case 4 :
		    printf("\n[PENGURANGAN]\n");

		    bil1_kurang:
            bil1 = isAngka("bilangan 1");
            if(isnan(bil1))goto bil1_kurang;

		    bil2_kurang:
            bil2 = isAngka("bilangan 2");
            if(isnan(bil2))goto bil2_kurang;

		    printf("Hasil %.2f - %.2f = %.2f\n", bil1, bil2, bil1-bil2);
            break;

        case 5:
            printf("\n[MODULUS]\n");

            mod1:
            bil1 = isAngka("bilangan 1");
            if(isnan(bil1))goto mod1;

		    mod2:
            bil2 = isAngka("bilangan 2");
            if(isnan(bil2))goto mod2;

            float hasil = fmod(bil1, bil2);

		    printf("Hasil %.2f modulus %.2f = %.2f\n", bil1, bil2, hasil);
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
