#ifndef XChainTransaction_hpp
#define XChainTransaction_hpp

#include "XTransaction.hpp"

class XChainTransaction : public XTransaction
{
    Q_OBJECT
public:
    XChainTransaction(QObject *parent = nullptr);
    ~XChainTransaction();

    XChainTransaction &operator<<(XTransaction *transaction);

    QVector<XTransaction*> getTransactions() const;

    XTransaction *currentTransaction() const;

    XTransaction *first() const;
    XTransaction *last() const;

    uint transactionsMaxCount() const;
    void setTransactionsMaxCount(uint count);

Q_SIGNALS:
    void transactionStarted(XTransaction *transaction);
    void transactionFinished(XTransaction *transaction);

protected:
    void startEvent() override;

protected Q_SLOTS:
    void onTransactionFinished(XTransaction *transaction);
    void onTransactionProgressChanged(XTransaction *transaction, uint percentage);
    void runTransactionAtIndex(uint index);

private:
    class Private;
    Private *d;

};

#endif // XChainTransaction_hpp
