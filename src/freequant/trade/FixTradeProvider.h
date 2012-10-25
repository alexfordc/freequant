#ifndef FQ_TRADE_FIXTRADEPROVIDER_H
#define FQ_TRADE_FIXTRADEPROVIDER_H

#include <freequant/trade/TradeProvider.h>

namespace FreeQuant {

class FixTradeProvider : public TradeProvider {
public:
    explicit FixTradeProvider(FreeQuant::TradeProvider::Callback *callback = 0);
    FixTradeProvider(std::string connection);
    virtual ~FixTradeProvider();

    void connect();
    void disconnect();
    bool isConnected() const;
    std::string name() const { return "FIX"; }

    void logon();
    void logout();

    std::vector<std::string> availableExchanges() const;
    std::vector<std::string> availableInstruments() const;

    void sendOrder(FreeQuant::Order& order);
    void cancelOrder(FreeQuant::Order& order);
    void replaceOrder(FreeQuant::Order& order);

    void subscribe(std::vector<std::string> symbols);
    void unsubscribe(std::vector<std::string> symbols);

private:
    class Impl;
    Impl *_impl;
};


} // namespace FreeQuant

#endif // FQ_TRADE_FIXTRADEPROVIDER_H
