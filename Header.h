#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <functional>
#include <iostream>

class Command {
private:


    struct BaseFunction {
        virtual ~BaseFunction() = default;
        virtual std::unique_ptr<BaseFunction> clone() const = 0;  // if you want to be able to copy the thing
    };



    template <typename F>
    struct RealFunction : BaseFunction {
        std::function<F> function;
        template <typename G>
        RealFunction(G&& function) : function(std::forward<G>(function)) {}
        std::unique_ptr<BaseFunction> clone() const override { return std::make_unique<RealFunction<F>>(*this); }
    };



    std::unordered_map<std::string, std::unique_ptr<BaseFunction>> funcs;



public:
    template <typename... Args>
    void register_function(std::string name, void (*func)(Args...)) {
        funcs.try_emplace(std::move(name), std::make_unique<RealFunction<void(std::decay_t<Args>...)>>(func));
    }

    template <typename Sig, typename F>
    void register_function(std::string name, F&& func) {
        funcs.try_emplace(std::move(name), std::make_unique<RealFunction<Sig>>(func));
    }

    template <typename... Args>
    void call_function(const std::string& name, Args&&... args) {
        using Sig = void(std::decay_t<Args>...);
        if (auto it = funcs.find(name); it != funcs.end()) {
            if (auto x = dynamic_cast<RealFunction<Sig>*>(it->second.get()))
                x->function(std::forward<Args>(args)...);
        }
    }
};

