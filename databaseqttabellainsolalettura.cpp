/**************************
MODELLO
***************************/

// Ottengo un reference ad un database precedentmente "configurato"
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


