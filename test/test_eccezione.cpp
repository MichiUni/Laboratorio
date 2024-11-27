#include "gtest/gtest.h"
#include "chat.h"
#include "utente.h"
#include "MessaggioNonValidoException.h"

//Verifica che venga lanciata un'eccezione MessaggioNonValidoException quando si tenta di aggiungere
// un messaggio non valido a una chat.
TEST(MessaggioNonValidoExceptionTest, LanciaEccezioneMessaggioNonValido) {
    // Crea due utenti
    Utente utente1(1, "Alice", "123456789");
    Utente utente2(2, "Bob", "987654321");
    Utente utenteNonValido(3, "Charlie", "111222333");

    // Crea una chat tra utente1 e utente2
    Chat chat(utente1, utente2);

    // Messaggio non valido (mittente non appartiene alla chat)
    Messaggio messaggioInvalido(utenteNonValido, utente1, "Questo messaggio non dovrebbe essere valido");

    // Verifica che venga lanciata l'eccezione corretta
    EXPECT_THROW(chat.aggiungiMessaggio(messaggioInvalido), MessaggioNonValidoException);
}
//Dopo aver catturato l'eccezione, controlla che il messaggio restituito dalla funzione what() sia corretto.
TEST(MessaggioNonValidoExceptionTest, VerificaMessaggioEccezione) {
    // Crea due utenti
    Utente utente1(1, "Alice", "123456789");
    Utente utente2(2, "Bob", "987654321");
    Utente utenteNonValido(3, "Charlie", "111222333");

    // Crea una chat tra utente1 e utente2
    Chat chat(utente1, utente2);

    // Messaggio non valido
    Messaggio messaggioInvalido(utenteNonValido, utente1, "Messaggio non valido");

    try {
        chat.aggiungiMessaggio(messaggioInvalido);
    } catch (const MessaggioNonValidoException &e) {
        // Verifica che il messaggio di errore sia corretto
        EXPECT_STREQ(e.what(), "Errore: Il messaggio non appartiene a questa chat.");
    }
}
