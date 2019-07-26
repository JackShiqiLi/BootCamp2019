function [ys_, params, info] = rbc_model_steadystate2(ys_, exo_, params)
% Steady state generated by Dynare preprocessor
    info = 0;
    ys_(6)=1/params(2)-(1-params(8));
    ys_(5)=params(6);
    ys_(3)=(params(7)*ys_(5)^(1-params(7))/ys_(6))^(1/(1-params(7)));
    ys_(1)=ys_(5)^(1-params(7))*ys_(3)^params(7);
    ys_(4)=params(8)*ys_(3);
    ys_(2)=ys_(1)-ys_(4);
    ys_(8)=0;
    ys_(7)=(1-params(7))*ys_(1)/ys_(5);
    params(5)=ys_(7)*(ys_(2)-ys_(2)*params(1))^((-1)/params(3))/ys_(5)^(1/params(4));
    ys_(9)=100*log(ys_(1));
    ys_(10)=100*log(ys_(2));
    ys_(11)=100*log(ys_(4));
    ys_(12)=100*log(ys_(5));
    ys_(13)=100*log(ys_(7));
    ys_(14)=ys_(6)*400;
    % Auxiliary equations
    check_=0;
end
