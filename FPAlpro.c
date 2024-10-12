#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//jumlah max notes
#define max_notes 100

//sebuah fungsi untuk catatan
struct Note {
    char judul[50];
    char isi[500];
};

//jumlah awal catatan saat program dijalankan
struct Note notes[max_notes];
int jumlah = 0;

//fungsi menambahkan catatan
void tambah() {
    //saat notes sudah penuh
    if (jumlah >= max_notes) {
        printf("---------------------------\n");
        printf("Batas catatan telah tercapai.\n");
        return;
    }

    //saat notes belum penuh
    struct Note baru;
    printf("Judul catatan: \n");
    getchar();
    fgets(baru.judul, 100, stdin);
    printf("-----------\n");
    printf("Isi catatan: \n");
    fgets(baru.isi, 100, stdin);

    notes[jumlah++] = baru;
    system("cls");
}

//fungsi melihat catatan
void lihat() {
    //saat catatan belum ditambahkan
    if (jumlah == 0) {
        printf("Tidak ada catatan yang tersedia.\n");
        return;
    }

    //catatan tersedia
    printf("Daftar Catatan:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("---------------\n");
        printf("Catatan %d:\n", i + 1);
        printf("Judul: %s\n", notes[i].judul);
    }

    //kembali ke menu utama
    int nomor;
    printf("Pilih nomor catatan untuk melihat isinya (0 untuk kembali): ");
    scanf("%d", &nomor);

    if (nomor == 0) {
        system("cls");
        return;
    }

    //pilihan input tidak sesuai
    if (nomor < 1 || nomor > jumlah) {
        system("cls");
        printf("Nomor catatan tidak valid.\n");
        return;
    }
    
    //pilihan input sesuai
    printf("-----------------\n");
    system("cls");
    printf("Isi Catatan %d:\n", nomor);
    printf("%s", notes[nomor - 1].isi);
}

//fungsi menghapus catatan
void hapus() {
    //saat catatan belum ditambahkan
    if (jumlah == 0) {
        printf("Tidak ada catatan yang tersedia.\n");
        return;
    }
    //saat catatan tersedia
    int nomor;
    printf("Masukkan nomor catatan yang ingin dihapus:  \n");
    
    for (int i = 0; i < jumlah; i++) {
        printf("%d. ", i + 1);
        printf("Judul: %s", notes[i].judul);
        printf("\n");
    }
    scanf("%d", &nomor);

    //input tidak sesuai
    if (nomor < 1 || nomor > jumlah) {
        system("cls");
        printf("Nomor catatan tidak valid.\n");
        return;
    }
    //input sesuai
    for (int i = nomor - 1; i < jumlah - 1; i++) {
        notes[i] = notes[i + 1];
    }

    jumlah--;
    system("cls");
    printf("Catatan telah dihapus\n");
}

int main() {
    int inp;

    do {
        printf("==Menu==\n");
        printf("1. Tambah Catatan\n");
        printf("2. Lihat Catatan\n");
        printf("3. Hapus Catatan\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &inp);

        system("cls");

        switch (inp) {
            case 1:
                tambah();
                printf("Catatan telah ditambahkan.\n");
                break;
            case 2:
                lihat();
                break;
            case 3:
                hapus();
                break;
            case 0:
                printf("Terima kasih^^\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        printf("\n");
    } while (inp != 0);

    return 0;
}