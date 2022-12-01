#include "FamilyFileReader.h"

void FamilyFileReader::SetJobReader(JobFileReader* reader) { _jobReader = reader; }
void FamilyFileReader::SetPurchaseReader(PurchaseFileReader* reader) { _purchaseReader = reader; }