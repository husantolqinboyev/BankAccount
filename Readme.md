# Cyber Bank - Zamonaviy Bank Boshqaruv Tizimi

**Cyber Bank** — bu C++ va Qt freymvorki yordamida yaratilgan, foydalanuvchilarga bank hisob raqamlarini boshqarish imkonini beruvchi interaktiv va futuristik ish stoli ilovasi. Loyiha zamonaviy "Cyber" dizayn uslubida ishlangan bo'lib, foydalanuvchi tajribasini (UX) yaxshilash uchun turli vizual effektlar va tranzaksiya simulyatsiyalarini o'z ichiga oladi.

## 🚀 Loyiha nima qila oladi? (Imkoniyatlar)

Loyiha to'liq funksional bank hisob-kitob tizimini taqdim etadi:

1.  **Hisob Ochish:** Foydalanuvchi o'z ismi va boshlang'ich mablag'i bilan asosiy hisob raqamini ochishi mumkin.
2.  **Ko'p Tarmoqli Hisoblar:** Tizim avtomatik ravishda asosiy hisobdan tashqari yana ikkita qo'shimcha ("Hisob 1" va "Hisob 2") hisoblarni yaratadi.
3.  **Mablag' Kiritish (Deposit):** Hisobga istalgan miqdorda (faqat musbat summa) pul qo'shish imkoniyati.
4.  **Mablag' Yechish (Withdraw):** Balansni tekshirgan holda hisobdan pul yechib olish. Agar mablag' yetarli bo'lmasa, tizim xatolik haqida ogohlantiradi.
5.  **Hisoblararo O'tkazma (Transfer):** "Hisob 1" va "Hisob 2" o'rtasida real vaqt rejimida pul o'tkazmalarini amalga oshirish.
6.  **Tranzaksiyalar Tarixi:** Amalga oshirilgan har bir operatsiya (depozit, yechish, o'tkazma) vaqt va tafsilotlari bilan tarixda saqlanadi.
7.  **Hisobni Nolga Qaytarish (Reset):** Barcha ma'lumotlarni va balansni tozalash imkoniyati.

## 💎 Xususiyatlari va Afzalliklari

*   **Futuristik Dizayn:** "Cyberpunk" uslubidagi quyuq fon, neon rangli tugmalar va yorqin interfeys.
*   **Dinamik Balans Indikatori:** Balans miqdoriga qarab ranglar o'zgaradi:
    *   🔴 **Qizil:** Balans bo'sh (0 so'm).
    *   🟡 **Sariq:** Balans kam (10,000 so'mdan kam).
    *   🟢 **Yashil:** Balans yetarli darajada.
*   **Tranzaksiya Simulyatsiyasi:** Pul o'tkazmalari va amallarda `QTimer` va `QProgressBar` yordamida real bank jarayonlari simulyatsiya qilinadi.
*   **Xavfsiz va Ishonchli:** Manfiy summalarni kiritish yoki balansdan ortiqcha pul yechish kabi noto'g'ri operatsiyalar dasturiy darajada bloklangan.
*   **Intuitiv Interfeys:** Foydalanuvchi uchun tushunarli holat xabarlari va ogohlantirishlar paneli.

## 🛠 Texnik darajasi va Stack

Loyiha **Obyektga Yo'naltirilgan Dasturlash (OOP)** tamoyillari asosida qurilgan:

*   **Til:** C++ (standart 11/14/17).
*   **Freymvork:** Qt 5.x / 6.x.
*   **Arxitektura:** Model-View-Controller (MVC) ga yaqin yondashuv. `Account` klassi barcha mantiqiy jarayonlarni boshqaradi, `MainWindow` esa UI bilan bog'laydi.
*   **UI Komponentlari:** QWidget, QLayouts, QLineEdit, QSpinBox, QTextEdit, QProgressBar va maxsus CSS (Qt Style Sheets).

## 💻 Ishga tushirish talablari

Dasturni ishga tushirish uchun kompyuteringizda quyidagilar o'rnatilgan bo'lishi kerak:
1.  **Qt Creator** IDE.
2.  **C++ Kompilyatori** (GCC, Clang yoki MSVC).
3.  **CMake** yoki **QMake** loyiha menejeri.

---
*Loyiha ta'lim va amaliyot maqsadida yaratilgan bo'lib, bank tizimlarining mantiqiy asoslarini o'rganish uchun ajoyib namuna hisoblanadi.*
