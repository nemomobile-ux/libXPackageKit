#ifndef XINSTALLTRANSACTION_HPP
#define XINSTALLTRANSACTION_HPP

#include "XPackageKitTransaction.hpp"
#include <Transaction>

class XInstallTransaction : public XPackageKitTransaction
{
    Q_OBJECT
public:
    XInstallTransaction(QObject *parent = nullptr);

private Q_SLOTS:
    void onTransactionPackage(PackageKit::Transaction::Info info, const QString &packageID, const QString &summary);

protected:
    PackageKit::Transaction *createTransaction() override;
};

#endif // XINSTALLTRANSACTION_HPP
