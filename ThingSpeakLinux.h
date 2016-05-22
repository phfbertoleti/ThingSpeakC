/*
Módulo: Header geral da comunicação com ThingSpeak (via Socket TCP) para Linux
Autor:  Pedro Bertoleti
Data:   05/2016
*/

//defines
#define ERRO_THINGSPEAK_OFFLINE  0
#define ERRO_CONEXAO_THINGSPEAK  1
#define ERRO_AO_ABRIR_SOCKET     2
#define ERRO_PARAMETROS          3
#define ENVIO_COM_SUCESSO        4


//variáveis globais
char EnviaRequisicaoThingSpeak(int NumCampos, int * ArrayCampos, char * Chave, int TamChaves);

//prototypes globais