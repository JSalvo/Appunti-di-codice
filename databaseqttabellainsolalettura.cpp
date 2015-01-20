/**************************
MODELLO
***************************/

// Ottengo un reference ad un database precedentmente "configurato"
// il parametro false, indica che se non vi è connessione al db, non si tenterà di stabilirla automaticamente
QSqlDatabase db = QSqlDatabase::database("Database precedentemente inizializzato", false);

// Creo un modello per poter accedere ai dati del database in sola lettura
QSqlQueryModel *model = new QSqlQueryModel();

// Indico la query che il modello deve rappresentare. Evitare di utilizzare la sintassi
// SELECT * in modo da avere più controllo sul proprio programma
model->setQuery("SELECT id, name, address FROM customers WHERE 1", db);

// Imposto i nomi delle colonne per la visualizzazione. L'utilizzo della funzione tr, mi permetterà
// con QtLinguist, di "Localizzare" il programma in altre lingue
model->setHeaderData(1, Qt::Horizontal, tr("Nome"));
model->setHeaderData(2, Qt::Horizontal, tr("Indirizzo"));


/**************************
VISTA
***************************/

// Associo il modello alla vista
tableView_customers->setModel(model);

// Nascondo le colonne che non voglio vengano visualizzate
tableView_customers->setColumnHidden(0, true);

// Imposto il comportamento di "stretching" delle colonne
tableView_customers->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

// Specifico che Sarà possibile selezionare solo righe (non ad esempio celle) della tabella
tableView_customers->setSelectionBehavior(QAbstractItemView::SelectRows);

// Indico che sarà possibile selezionare solo una riga alla volta
tablwView_customers->setSelectionMode(QAbstractItemView::SingleSelection)


/**************************
SEGNALI
***************************/

// Intercetto il segnale che viene emesso nel momento in cui la riga correntemente selezionata viene cambiata e lo
// redireziono su uno slot, che si occuperà di gestire l'evento. Lo slot sarà definito nella classe in cui questo
// codice è scritto (this)

QObject::connect(
  tableView_customers->selectionMode(), // Oggetto che genererà il segnale
  SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), // segnale emesso 
  this, // oggetto in cui lo slot è istanziato
  SLOT(currentCustomerRowChanged(QModelIndex, QModel, index))  // slot dell'oggetto this
);



